#include <iostream>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sstream>
#include <map>
using namespace std;


int find_first_newline(u_int8_t buffer[]){
    int i = 0;
    while (buffer[i] != '\n')
    {
        i++;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        cout << "Podaj odpowiednią liczbe argumentów." << endl;
        return 0;
    }
    string ip;
    int port;
    string file;
    int64_t size;
    unsigned char buf[sizeof(struct in6_addr)];
    if(inet_pton(AF_INET, argv[1], buf) <= 0){
        exit(0);
    }
    ip = argv[1];
    port = stoi(argv[2]);
    file = argv[3];
    size = stoi(argv[4]);
    // cerr << ip << " " << port << " " << file << " " << size << endl;
    int elements= (size/1000)+1;
    bool* recived = new bool[elements];
    int mostlastrecived = -1;
    int lastsend = -1;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
		fprintf(stderr, "socket error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}
    struct sockaddr_in server_address;
	bzero (&server_address, sizeof(server_address));
	server_address.sin_family      = AF_INET;
	server_address.sin_port        = htons(port);
	inet_pton(AF_INET, ip.c_str(), &server_address.sin_addr);
    FILE * pFile;
    pFile = fopen (file.c_str() , "w");
    struct timeval tv; tv.tv_sec = 0; tv.tv_usec = 100;
    struct sockaddr_in 	sender;	
    socklen_t 			sender_len = sizeof(sender);
    u_int8_t 			buffer[IP_MAXPACKET+1];
    fd_set descriptors;
    FD_ZERO (&descriptors);
    FD_SET (sockfd, &descriptors);
    map<int, u_int8_t*> remembered;
    // cout << elements<< endl;
    while (mostlastrecived + 1 != elements)
    {
        for (int i = 1; i < 500 && mostlastrecived + i < elements; i++)
        {
            char* message = new char[50];
            strcpy(message, ("GET " + to_string((mostlastrecived + i)*1000) + " " + to_string((mostlastrecived + i >= elements - 1) ? size % 1000 : 1000) +"\n").c_str());
            // cout << message;
            ssize_t message_len = strlen(message);
            if (!recived[mostlastrecived + i])
            {
                if (sendto(sockfd, message, message_len, 0, (struct sockaddr*) &server_address, sizeof(server_address)) != message_len) {
                    fprintf(stderr, "sendto error: %s\n", strerror(errno)); 		
                }
            }
            free(message);

        }
        
        
        while (true)
        {
            int ready = select (sockfd+1, &descriptors, NULL, NULL, &tv);
            (void)ready;
            ssize_t datagram_len = recvfrom (sockfd, buffer, IP_MAXPACKET, MSG_DONTWAIT, (struct sockaddr*)&sender, &sender_len);
            if (datagram_len < 0) {
                break;
            }
            stringstream str;
            str << buffer;
            string s1, s2, s3,s4;
            str >> s1;
            str >> s2;
            str >> s3;
            // cout << s1 << " " << s2 << " " << s3 << " " << s4 <<endl;
            int which_came = stoi(s2)/1000;
            if (!recived[which_came])
            {
                recived[which_came] = true;
                u_int8_t *pom = new u_int8_t[1000];
                int newline = find_first_newline(buffer);
                memcpy(pom, buffer + newline + 1, stoi(s3));
                remembered[which_came] = pom;
            }
            while(mostlastrecived + 1 <= elements &&recived[mostlastrecived+1]){
                mostlastrecived++;
                fwrite(remembered[mostlastrecived], sizeof(u_int8_t), (mostlastrecived >= elements - 1) ? size % 1000 : 1000, pFile);
                free(remembered[mostlastrecived]);
                remembered.erase(mostlastrecived);
            }
            // cout << mostlastrecived<<endl;
        }
        

    }
    fclose(pFile);
    return 0;
}

