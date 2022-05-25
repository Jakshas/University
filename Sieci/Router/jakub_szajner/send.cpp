// Jakub Szajner 315700
#include "router.h"

std::chrono::_V2::steady_clock::time_point last_time = chrono::steady_clock::now();

void send_to_neighbours(int sockfd, vector<Network> *vect){
    delete_disabled(vect);
    auto now = chrono::steady_clock::now();
    if (chrono::duration_cast<chrono::seconds>(now - last_time).count() >= 5)
    {
        last_time = now;
        write_table(vect);
        for (auto &&v1 : *vect)
        {
            if (v1.route == "D")
            {
                unsigned char * broadcast = get_broadcast(v1.ip); 
                string s = to_string(broadcast[0])+'.'+to_string(broadcast[1])+'.'+to_string(broadcast[2])+'.'+to_string(broadcast[3]);
                
                for (auto &&v2 : *vect)
                {
                    struct sockaddr_in server_address;
                    bzero (&server_address, sizeof(server_address));
                    server_address.sin_family      = AF_INET;
                    server_address.sin_port        = htons(54321);
                    inet_pton(AF_INET, s.c_str() , &server_address.sin_addr);
                    unsigned char* message = prepare_data(v2.ip, v2.distance);
                    ssize_t message_len = 9;
                    if (!v2.reachable)
                    {
                        set_distance_infinite(message);
                    }
                    if (!v2.reachable && chrono::duration_cast<chrono::seconds>(now - v2.last_recived).count() >= 15 )
                    {
                        continue;
                    }
                    if (sendto(sockfd, message, message_len, 0, (struct sockaddr*) &server_address, sizeof(server_address)) != message_len) {
                        for (auto &&i : *vect)
                        {
                            if (if_equal_ip(get_network(broadcast), i.ip))
                            {
                                i.reachable = false;
                            }
                        }	
                    }else
                    {
                        for (auto &&i : *vect)
                            {
                            if (if_equal_ip(get_network(broadcast), i.ip))
                            {
                                i.reachable = true;
                            }
                        }
                    }
                }
            }
        }
    }
}
