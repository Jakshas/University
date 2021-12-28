#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i = 0;
    i++;
    int *p = malloc(sizeof(int)*8);// int[8]
    int tab[8];
    p[1] = 10;
    int j = *p;
    return 0;
}
 