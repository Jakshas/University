// Jakub Szajner 315700
#include "router.h"

void recive_datagram(int sockfd, vector<Network> *vect){
    struct sockaddr_in 	sender;	
	socklen_t 			sender_len = sizeof(sender);
	u_int8_t 			buffer[IP_MAXPACKET+1];
    fd_set descriptors;
    FD_ZERO (&descriptors);
    FD_SET (sockfd, &descriptors);
    struct timeval tv; tv.tv_sec = 5; tv.tv_usec = 0;
    int ready = select (sockfd+1, &descriptors, NULL, NULL, &tv);
    (void)ready;
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
