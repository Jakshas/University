#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 2;
    
    printf("%d",(num &(num - 1)) == 0);
    return 0;
}
