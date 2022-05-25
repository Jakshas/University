// Jakub Szajner 315700

#include "traceroute.h"

int recive_signals(int sockfd,chrono::system_clock::time_point* timmer_end_tab, char ** bufferstr, int i, const char * ip){
        struct sockaddr_in 	sender;
        socklen_t 			sender_len = sizeof(sender);
        u_int8_t 			buffer[IP_MAXPACKET];
        char sender_ip_str[20];
        fd_set descriptors;
        FD_ZERO (&descriptors);
        FD_SET (sockfd, &descriptors);
        struct timeval tv; tv.tv_sec = 1; tv.tv_usec = 0;
        int how_many_recived = 0;
        for (size_t j = 0; j < 3;)
        {
            int ready = select (sockfd+1, &descriptors, NULL, NULL, &tv);
            if (ready == 1)
            {
                timmer_end_tab[j] = std::chrono::high_resolution_clock::now();
                ssize_t packet_len = recvfrom (sockfd, buffer, IP_MAXPACKET, MSG_DONTWAIT, (struct sockaddr*)&sender, &sender_len);
                if (packet_len < 1)
                {
                    cerr << "Wystąpił błąd w odbieraniu dancyh"<< endl;
                    return -1;
                }
                
                inet_ntop(AF_INET, &(sender.sin_addr), sender_ip_str, sizeof(sender_ip_str));

                struct ip* ip_header = (struct ip*) buffer;
                u_int8_t* icmp_packet = buffer + 4 * ip_header->ip_hl;
                struct icmp* icmp_header = (struct icmp*) icmp_packet;
                icmp_packet += 8;
                icmp_packet += 4 * ((struct ip*) icmp_packet)->ip_hl;
                struct icmp* icmp_real_header = (struct icmp*) icmp_packet;
                if ((getpid() == icmp_real_header->icmp_hun.ih_idseq.icd_id && icmp_real_header->icmp_hun.ih_idseq.icd_seq == i) || (getpid() == icmp_header->icmp_hun.ih_idseq.icd_id && strcmp(sender_ip_str, ip) == 0))
                {
                    strcpy(bufferstr[j],sender_ip_str);
                    how_many_recived++;
                    j++;
                }
            }
            else if (ready == 0)
            {
                j++;
            }
        }
        return how_many_recived;
}