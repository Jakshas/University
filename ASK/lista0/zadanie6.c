#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 11;
    num = ((num>>24)&0xff) | // move byte 3 to byte 0
                    ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((num>>8)&0xff00) | // move byte 2 to byte 1
                    ((num<<24)&0xff000000); // byte 0 to byte 3
    printf("%d",num);
    return 0;
}
