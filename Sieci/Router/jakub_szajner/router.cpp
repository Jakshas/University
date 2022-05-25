// Jakub Szajner 315700
#include "router.h"

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

