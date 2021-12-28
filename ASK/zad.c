#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
extern uint64_t bitrev(uint64_t);

unsigned long reverse(unsigned long num) {
  unsigned long s = 8 * sizeof(num); // bit size; must be power of 2
  unsigned long mask = ~0;
  while ((s >>= 1) > 0) {
    mask ^= (mask << s);
    num = ((num >> s) & mask) | ((num << s) & ~mask);
  }
  return num;
}

int main(int argc, char const *argv[])
{
    printf("%"PRIu64"\n",(uint64_t)bitrev(0x232323ULL));
    printf("%"PRIu64"\n",(uint64_t)reverse(0x232323ULL));
    return 0;
}
//00000000 00000000 00000000 00000000 00000000 00100011 00100011 00100011
//00000000 00100011 00100011 00100011 00000000 00000000 00000000 00000000
//00100011 00100011 00000000 00100011 00000000 00000000 00000000 00000000
//00100011 00100011 00100011 00000000 00000000 00000000 00000000 00000000
//00110010 00110010 00110010 00000000 00000000 00000000 00000000 00000000
//01001000 11001000 11001000 10000000 00000000 00000000 00000000 00000000