// Jakub Szajner 315700

#include "traceroute.h"

int main(int argc, char const *argv[])
{
    if(argc != 2){
        cout << "Podaj adres ip jako jeden argument programu." << endl;
        return 0;
    }
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, argv[1], &(sa.sin_addr)) < 1){
        cout << "Wprowadź porprawny adress IP. ddd.ddd.ddd.ddd"  << endl;
        return 0;
    }
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0) {
        cerr << "socket error: " << errno;
		return EXIT_FAILURE;
	}

    char ** bufferstr = make_strbuff();
    int i = 1;
    char * answear_string;
    chrono::high_resolution_clock::now();
    chrono::system_clock::time_point timmer_start_tab[3];
    chrono::system_clock::time_point timmer_end_tab[3];

    do{
        send_three_signals(i,argv[1],sockfd,timmer_start_tab);
        int how_many_recived = recive_signals(sockfd, timmer_end_tab,bufferstr,i,argv[1]);
        if (how_many_recived == 3)
        {
            printf ("%i. %s %dms\n", i,answear_string = check_diffrent_ip(bufferstr),avarge_time(timmer_start_tab,timmer_end_tab));
        }else{
            if (how_many_recived > 0)
            {
                printf ("%i. %s ???\n", i, answear_string = check_diffrent_ip(bufferstr));
            }else{
                if (how_many_recived < 0)
                {
                    return 0;
                }
                else
                printf ("%i. *\n", i);
            }
        }
        i++;
    }while (strcmp(answear_string, argv[1]) != 0 && i <= 30);

    return 0;
}

