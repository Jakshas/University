#include <stdio.h>

int main(int argc, char const *argv[])
{
    {
        int x = 10;
        int y = 2;
        x = x << y;
        printf("%d \n", x);
    }
    {
        int x = 10;
        int y = 2;
        x = x >> y;
        printf("%d \n", x);
    }
    {
        int x = 10;
        int y = 2;
        x =x - (x >> y);
        printf("%d \n", x);
    }
    {
        int x = 12;
        int y = 2;
        x = (x >> y);
        printf("%d \n", x);
    }
    return 0;
}
