// Jakub Szajner 315700

#include "traceroute.h"

void send_three_signals(int i,const char * ip, int sockfd, chrono::system_clock::time_point timmer_start_tab[3]){
    struct icmp header;
    header.icmp_type = ICMP_ECHO;
    header.icmp_code = 0;
    header.icmp_hun.ih_idseq.icd_id = getpid();
    header.icmp_hun.ih_idseq.icd_seq = i;
    header.icmp_cksum = 0;
    header.icmp_cksum = compute_icmp_checksum ((u_int16_t*)&header, sizeof(header));

    struct sockaddr_in recipient;
    bzero (&recipient, sizeof(recipient));
    recipient.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &recipient.sin_addr);

    int ttl = i;
    
    setsockopt (sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));

    for (size_t j = 0; j < 3; j++)
    {
        sendto (
            sockfd,
            &header,
            sizeof(header),
            0,
            (struct sockaddr*)&recipient,
            sizeof(recipient)
        );
        timmer_start_tab[j] = std::chrono::high_resolution_clock::now();
    }
}