// Jakub Szajner 315700

#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <assert.h>
#include <cstring>
#include <string>
#include <chrono>

using namespace std;

u_int16_t compute_icmp_checksum (const void *buff, int length);

char * check_diffrent_ip(char ** buffer);

char ** make_strbuff();

int recive_signals(int sockfd,chrono::system_clock::time_point* timmer_end_tab, char ** bufferstr, int i, const char * ip);

void send_three_signals(int i,const char * ip, int sockfd, chrono::system_clock::time_point timmer_start_tab[3]);

int avarge_time(chrono::system_clock::time_point* start, chrono::system_clock::time_point* end);
