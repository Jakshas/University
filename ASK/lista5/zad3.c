#include <stdint.h>

uint32_t puzzle3(uint32_t n, uint32_t d)
{
    uint64_t nowe_d = ((uint64_t)d)<<32;
    uint64_t nowe_n = n;
    uint32_t wyn = 0;
    for(uint32_t mask = 0x80000000; mask > 0; mask >>= 1)
    {
        nowe_n *= 2;
        if(nowe_n >= nowe_d)
        {
            wyn |= mask;
            nowe_n -= nowe_d;
        }
    }
    return wyn;
}

int main(int argc, char const *argv[])
{
    int x = puzzle3(9,3);
    return 0;
}
