#include <stdio.h>
#include <stdint.h>

extern uint64_t addsb(uint64_t);

static void print(uint64_t x) {
    for (int i = 63; i >= 0; i--) {
        printf("%ld", (x >> i) & 1);
        if (i == 8 || i == 24 || i == 16 || i == 32 || i == 48 || i == 40 || i == 56)
            printf("%c", ' ');
    }
    printf("%c", '\n');
}


int main(int argc, char const *argv[])
{
    uint64_t i = addsb(0x0000000000000000);
    print(0x0000000000000000);
    print(i);
    printf("%ld\n",i);
    return 0;
}
