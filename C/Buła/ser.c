
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){

int sock_s /*nasluch*/, sock_k /*wysylanie*/;
struct sockaddr_in serwer, klient;

sock_s = socket(AF_INET, SOCK_STREAM, 0);

serwer.sin_family = AF_INET;
serwer.sin_addr.s_addr = inet_addr("127.0.0.1");
serwer.sin_port = htons(3333);

bind(sock_s, (struct sockaddr*)&serwer, sizeof(serwer));

listen(sock_s, 3);

while(1){

sock_k = accept(sock_s, (struct sockaddr*) NULL, NULL);
write(sock_k, "hello od serwera", 20);

close(sock_k);

}





return 0;
}