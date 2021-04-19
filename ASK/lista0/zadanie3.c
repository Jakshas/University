#include <stdio.h>

int main(int argc, char const *argv[])
{
    {   //p1 
        int x = 7;
        int k = 2;
        k = 1 << k;
        k = ~k;
        x = x & k;
        printf("%d \n", x);
        }
    {   //p2
        int x = 7;
        int k = 4;
        k = 1 << k;
        x = x | k;
        printf("%d \n", x);
    }
        {   //p2
        int x = 7;
        int k = 1;
        k = 1 << k;
        x = x ^ k;
        printf("%d \n", x);
    }
}
