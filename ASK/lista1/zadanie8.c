#include <stdint.h>

void secret(uint8_t *to, uint8_t *from, size_t count) {
    size_t n = (count + 7) / 8;
    switch (count % 8) {
        case 0: do { *to++ = *from++;
        case 7:      *to++ = *from++;
        case 6:      *to++ = *from++;
        case 5:      *to++ = *from++;
        case 4:      *to++ = *from++;
        case 3:      *to++ = *from++;
        case 2:      *to++ = *from++;
        case 1:      *to++ = *from++;
        } while (--n > 0);
    }
}

int main(int argc, char const *argv[])
{
    uint8_t to[8];
    for (uint8_t i = 0; i < 10; i++)
    {
        to[i] = i;
    }
    uint8_t from[8];
        for (uint8_t i = 0; i < 10; i++)
    {
        from[8-i] = i;
    }
    secret(to,from,11);
    return 0;
}
