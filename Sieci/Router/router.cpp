#include <iostream>
#include <fstream>
#include <vector>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <chrono>

using namespace std;

std::chrono::_V2::steady_clock::time_point last_time = chrono::steady_clock::now();

class Network{
    public:
        unsigned char *ip;
        uint32_t distance;
        string route = "D";
        chrono::_V2::steady_clock::time_point last_recived;
        bool reachable = true;
    Network(unsigned char *ip, int distance):ip(ip),distance(distance) {}
};

unsigned char * convert_ip(string ip){
    unsigned char *tab = new unsigned char[5];
    for (int i = 0; i < 3; i++)
    {
        string token = ip.substr(0, ip.find("."));
        ip.erase(0, ip.find(".") + 1);
        tab[i] = atoi(token.c_str());
    }
    string token = ip.substr(0, ip.find("."));
    ip.erase(0, ip.find("/") + 1);
    tab[3] = atoi(token.c_str());
    tab[4] = atoi(ip.c_str());
    return tab;
}

unsigned char * prepare_data(unsigned char * ip , uint32_t distance){
    unsigned char * c = new unsigned char[9];
    for (size_t i = 0; i < 5; i++)
    {
        c[i] = ip[i];
    }
    uint32_t mask = 0xFF000000;
    for (size_t i = 0; i < 4; i++)
    {
        c[5+i] = (distance & mask) >> (8 * (3 - i));
        mask = mask >> 8;
    }
    uint pom = 0;
    for (int i = 0; i < 4; i++)
    {
        pom = pom + c[5+i];
        if (i<3)
        {
            pom = pom << 8;
        }
    }
    return c;
}


unsigned char * get_broadcast(unsigned char * ip){
    uint32_t mask = 0xFFFFFFFF;
    mask = mask >> ip[4];
    unsigned char * broadcast = new unsigned char[5];
    for (int i = 0; i < 4; i++)
    {
        broadcast[i] = ip[i] | (mask >> (24 - (8 * i)));
    }
    broadcast[4] = ip[4];
    return broadcast;
}

unsigned char * get_network(unsigned char * ip){
    uint32_t mask = 0xFFFFFFFF;
    mask = mask >> ip[4];
    mask = ~mask;
    unsigned char * broadcast = new unsigned char[5];
    for (int i = 0; i < 4; i++)
    {
        broadcast[i] = ip[i] & (mask >> (24 - (8 * i)));
    }
    broadcast[4] = ip[4];
    return broadcast;
}

void write_table(vector<Network> *vect){
    for (auto &&v1 : *vect){
        if (v1.route != "D" && v1.distance == UINT32_MAX)
        {
            continue;
        }
        cout << to_string(v1.ip[0])+'.'+to_string(v1.ip[1])+'.'+to_string(v1.ip[2])+'.'+to_string(v1.ip[3])+'/'+to_string(v1.ip[4]);
        if (v1.reachable)
        {
            cout <<" distance "<< v1.distance;
        }else{
            cout <<" unreachable";
        }
        
        if (v1.route == "D")
        {            
            cout << " connected directly"<< endl;
        }else{
            cout << " via " << v1.route << endl;
        }
    }
    cout << endl;
}

void delete_disabled(vector<Network> *vect){
    for (size_t i = 0; i < vect->size(); i++)
    {
        // cout << chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - vect->at(i).last_recived ).count() << "|" << (int)vect->at(i).ip[0]<<"." << (int)vect->at(i).ip[1]<<"."<< (int)vect->at(i).ip[2]<<"."<< (int)vect->at(i).ip[3]<<"/"<< (int)vect->at(i).ip[4]<< endl;
        if ((vect->at(i).route != "D" && chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - vect->at(i).last_recived).count() >= 15) /*|| (vect->at(i).route != "D" && vect->at(i).distance == 0) */)
        {
            vect->erase(vect->begin()+i);
            i--;
        }
    }
}

bool if_equal_ip(unsigned char* ip1, unsigned char * ip2){
    for (int i = 0; i < 5; i++)
    {
        if (ip1[i] != ip2[i])
        {
            return false;
        }
        
    }
    return true;
}

void set_distance_infinite(unsigned char * message){
    for (size_t i = 0; i < 4; i++)
    {
        message[5+i] = 255;
    }
}

void send_to_neighbours(int sockfd, vector<Network> *vect){
    delete_disabled(vect);
    auto now = chrono::steady_clock::now();
    if (chrono::duration_cast<chrono::seconds>(now - last_time).count() >= 5)
    {
        last_time = now;
        write_table(vect);
        for (auto &&v1 : *vect)
        {
            if (v1.route == "D")
            {
                unsigned char * broadcast = get_broadcast(v1.ip); 
                string s = to_string(broadcast[0])+'.'+to_string(broadcast[1])+'.'+to_string(broadcast[2])+'.'+to_string(broadcast[3]);
                
                for (auto &&v2 : *vect)
                {
                    struct sockaddr_in server_address;
                    bzero (&server_address, sizeof(server_address));
                    server_address.sin_family      = AF_INET;
                    server_address.sin_port        = htons(54321);
                    inet_pton(AF_INET, s.c_str() , &server_address.sin_addr);
                    unsigned char* message = prepare_data(v2.ip, v2.distance);
                    ssize_t message_len = 9;
                    if (!v2.reachable)
                    {
                        set_distance_infinite(message);
                    }
                    if (!v2.reachable && chrono::duration_cast<chrono::seconds>(now - v2.last_recived).count() >= 15 )
                    {
                        continue;
                    }
                    if (sendto(sockfd, message, message_len, 0, (struct sockaddr*) &server_address, sizeof(server_address)) != message_len) {
                        for (auto &&i : *vect)
                        {
                            if (if_equal_ip(get_network(broadcast), i.ip))
                            {
                                i.reachable = false;
                            }
                        }	
                    }else
                    {
                        for (auto &&i : *vect)
                            {
                            if (if_equal_ip(get_network(broadcast), i.ip))
                            {
                                i.reachable = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void load(char const *argv[], vector<Network> *vect){
    int n;
    ifstream MyReadFile(argv[1]);
    MyReadFile >> n;
    for (int i = 0; i < n; i++)
    {
        string ip, d;
        int distance;
        MyReadFile >> ip;
        MyReadFile >> d;
        MyReadFile >> distance;
        Network net(get_network(convert_ip(ip)),distance);
        net.last_recived = chrono::steady_clock::now();
        vect->push_back(net);
        
    }
}

bool find_in_vector(vector<Network> *vect, unsigned char * ip){
    for (auto &&v : *vect)
    {
        bool flag = true;
        for (int i = 0; i < 4; i++)
        {
            if (v.ip[i] != ip[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}

int get_distance_to_ip(char * ip, vector<Network> *vect){
    for (auto &&i : *vect)
    {
        unsigned char * tempip = convert_ip(ip);
        tempip[4] = i.ip[4];
        unsigned char * network = get_network(tempip);
        if (if_equal_ip(network, i.ip))
        {
            return i.distance;
        }
    }
    return 0;
}

void recive_datagram(int sockfd, vector<Network> *vect){
    struct sockaddr_in 	sender;	
	socklen_t 			sender_len = sizeof(sender);
	u_int8_t 			buffer[IP_MAXPACKET+1];
    fd_set descriptors;
    FD_ZERO (&descriptors);
    FD_SET (sockfd, &descriptors);
    struct timeval tv; tv.tv_sec = 5; tv.tv_usec = 0;
    int ready = select (sockfd+1, &descriptors, NULL, NULL, &tv);
	ssize_t datagram_len = recvfrom (sockfd, buffer, IP_MAXPACKET, MSG_DONTWAIT, (struct sockaddr*)&sender, &sender_len);
	if (datagram_len < 0) {
		return;
	}

	char sender_ip_str[20];
	inet_ntop(AF_INET, &(sender.sin_addr), sender_ip_str, sizeof(sender_ip_str));
    unsigned char *ip = new unsigned char[5];
    for (int i = 0; i < 5; i++)
    {
        ip[i] = buffer[i];
    }
    uint32_t dist = 0;
    for (int i = 0; i < 4; i++)
    {
        uint8_t temp = buffer[i+5];
        dist = dist + temp;
        if (i<3)
        {
            dist = dist << 8;
        }
    }
    if(dist == 0){
        return;
    }
    if (find_in_vector(vect, ip))
    {
        for (auto &&v : *vect)
        {
            bool flag = true;
            for (int i = 0; i < 4; i++)
            {
                if (v.ip[i] != ip[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                if (dist == UINT32_MAX && v.route != "D")
                {
                    v.distance = dist;
                }else{
                    if(dist != UINT32_MAX && v.distance != UINT32_MAX && v.distance > dist + get_distance_to_ip(sender_ip_str, vect)){
                        v.distance = dist + get_distance_to_ip(sender_ip_str, vect);
                        v.route = sender_ip_str; 
                    }
                    if (v.route == "D" || v.route == sender_ip_str)
                    {
                        v.last_recived = chrono::steady_clock::now();
                    }
                }
            }
        }
    }else{
 
        if(dist != UINT32_MAX){
            Network net(ip, dist + get_distance_to_ip(sender_ip_str, vect));
            net.route = sender_ip_str;
            net.last_recived = chrono::steady_clock::now();
            vect->push_back(net);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<Network> vect;
    load(argv,&vect);
    int sockfdout = socket(AF_INET, SOCK_DGRAM, 0);
    int sockfdin = socket(AF_INET, SOCK_DGRAM, 0);
    int broadcastPermission = 1;
    setsockopt (sockfdout, SOL_SOCKET, SO_BROADCAST, (void *)&broadcastPermission, sizeof(broadcastPermission));
    struct sockaddr_in server_address;
	bzero (&server_address, sizeof(server_address));
	server_address.sin_family      = AF_INET;
	server_address.sin_port        = htons(54321);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind (sockfdin, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
		fprintf(stderr, "bind error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}
    while (true)
    {
        send_to_neighbours(sockfdout, &vect);
        recive_datagram(sockfdin, &vect);
    }
    return 0;
}

