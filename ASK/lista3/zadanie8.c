#include <stdint.h>

int32_t float2int(int32_t f) {
  int32_t s = f >> 31;               /* -1 jeśli znak był ujemny */
  int32_t e = (f >> 23 & 255) - 127; /* wykładnik po odjęciu bias */
  uint32_t m = f << 8 | 0x80000000;  /* mantysa 1.xxx... dosunięta do lewej */
  /* TODO */
  // printf("s %d e %d m %u\n", s, e, m);
  // if (e >= 31) return 0x80000000;
  // if (e <= -1) return 0;
  // s jest -1 lub 0, my chcemy -1 lub 1, stąd s | 1
  // return (s | 1) * (m >> (31 - e));

  if (e >= 31) return 0x80000000;
  return ~(e >> 31) & ((s | 1) * (m >> (31 - e)));
}