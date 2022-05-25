// Jakub Szajner 315700

#include "traceroute.h"

u_int16_t compute_icmp_checksum(const void *buff, int length)
{
	u_int32_t sum;
	const u_int16_t* ptr = (u_int16_t*)buff;
	assert (length % 2 == 0);
	for (sum = 0; length > 0; length -= 2)
		sum += *ptr++;
	sum = (sum >> 16) + (sum & 0xffff);
	return (u_int16_t)(~(sum + (sum >> 16)));
}

char * check_diffrent_ip(char ** buffer){
    char * returnbuff = new char[60];
    if (strcmp(buffer[0],buffer[1]) == 0){
        strcpy(returnbuff,buffer[0]);
        if (strcmp(buffer[0],buffer[2]) != 0)
        {
            strcat(returnbuff," ");
            strcat(returnbuff,buffer[2]);
        }
    }else
    {
        strcpy(returnbuff,buffer[0]);
        strcat(returnbuff," ");
        strcpy(returnbuff,buffer[1]);
        if (strcmp(buffer[0],buffer[2]) != 0 && strcmp(buffer[0],buffer[2]) != 0)
        {
            strcat(returnbuff," ");
            strcpy(returnbuff,buffer[2]);
        }
    }
    return returnbuff;
}

char ** make_strbuff(){
    char ** bufferstr = new char*[3];
    bufferstr[0] = new char[20];
    bufferstr[1] = new char[20];
    bufferstr[2] = new char[20];
    return bufferstr;
}

int avarge_time(chrono::system_clock::time_point* start, chrono::system_clock::time_point* end){
    chrono::duration<int64_t, std::nano> sum_of_time = chrono::milliseconds(0);
    for (int i = 0; i < 3; i++)
    {
        sum_of_time += end[i] - start[i];
    }
    return (sum_of_time/chrono::milliseconds(1))/3;
}
