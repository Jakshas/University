// Jakub Szajner 315700
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

class Network{
    public:
        unsigned char *ip;
        uint32_t distance;
        string route = "D";
        chrono::_V2::steady_clock::time_point last_recived;
        bool reachable = true;
    Network(unsigned char *ip, int distance):ip(ip),distance(distance) {}
};

void set_distance_infinite(unsigned char * message);

bool if_equal_ip(unsigned char* ip1, unsigned char * ip2);

unsigned char * get_network(unsigned char * ip);

unsigned char * get_broadcast(unsigned char * ip);

unsigned char * prepare_data(unsigned char * ip , uint32_t distance);

unsigned char * convert_ip(string ip);

void write_table(vector<Network> *vect);

void delete_disabled(vector<Network> *vect);

void load(char const *argv[], vector<Network> *vect);

bool find_in_vector(vector<Network> *vect, unsigned char * ip);

int get_distance_to_ip(char * ip, vector<Network> *vect);

void send_to_neighbours(int sockfd, vector<Network> *vect);

void recive_datagram(int sockfd, vector<Network> *vect);