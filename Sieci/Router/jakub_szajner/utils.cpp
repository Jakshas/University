// Jakub Szajner 315700
#include "router.h"

unsigned char * convert_ip(string ip){
    unsigned char *tab = new unsigned char[5];
    for (int i = 0; i < 3; i++)
    {
        string token = ip.substr(0, ip.find("."));
        ip.erase(0, ip.find(".") + 1);
        tab[i] = atoi(token.c_str());
    }
    string token = ip.substr(0, ip.find("."));
    ip.erase(0, ip.find("/") + 1);
    tab[3] = atoi(token.c_str());
    tab[4] = atoi(ip.c_str());
    return tab;
}

unsigned char * prepare_data(unsigned char * ip , uint32_t distance){
    unsigned char * c = new unsigned char[9];
    for (size_t i = 0; i < 5; i++)
    {
        c[i] = ip[i];
    }
    uint32_t mask = 0xFF000000;
    for (size_t i = 0; i < 4; i++)
    {
        c[5+i] = (distance & mask) >> (8 * (3 - i));
        mask = mask >> 8;
    }
    uint pom = 0;
    for (int i = 0; i < 4; i++)
    {
        pom = pom + c[5+i];
        if (i<3)
        {
            pom = pom << 8;
        }
    }
    return c;
}

unsigned char * get_broadcast(unsigned char * ip){
    uint32_t mask = 0xFFFFFFFF;
    mask = mask >> ip[4];
    unsigned char * broadcast = new unsigned char[5];
    for (int i = 0; i < 4; i++)
    {
        broadcast[i] = ip[i] | (mask >> (24 - (8 * i)));
    }
    broadcast[4] = ip[4];
    return broadcast;
}

unsigned char * get_network(unsigned char * ip){
    uint32_t mask = 0xFFFFFFFF;
    mask = mask >> ip[4];
    mask = ~mask;
    unsigned char * broadcast = new unsigned char[5];
    for (int i = 0; i < 4; i++)
    {
        broadcast[i] = ip[i] & (mask >> (24 - (8 * i)));
    }
    broadcast[4] = ip[4];
    return broadcast;
}

bool if_equal_ip(unsigned char* ip1, unsigned char * ip2){
    for (int i = 0; i < 5; i++)
    {
        if (ip1[i] != ip2[i])
        {
            return false;
        }
        
    }
    return true;
}

void set_distance_infinite(unsigned char * message){
    for (size_t i = 0; i < 4; i++)
    {
        message[5+i] = 255;
    }
}

int get_distance_to_ip(char * ip, vector<Network> *vect){
    for (auto &&i : *vect)
    {
        unsigned char * tempip = convert_ip(ip);
        tempip[4] = i.ip[4];
        unsigned char * network = get_network(tempip);
        if (if_equal_ip(network, i.ip))
        {
            return i.distance;
        }
    }
    return 0;
}