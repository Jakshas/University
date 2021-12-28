#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

int sock_fd;
struct sockaddr_in serwer;

sock_fd = socket(AF_INET,SOCK_STREAM,0);

serwer.sin_family = AF_INET;
serwer.sin_port = htons(3333);
serwer.sin_addr.s_addr = inet_addr("127.0.0.1");

connect(sock_fd, (struct sockaddr *)&serwer, sizeof(serwer));

int n=0;
char wiad[30];
while(n = read(sock_fd,wiad, 29)>0){
printf("%s", wiad);

}


return 0;
}
