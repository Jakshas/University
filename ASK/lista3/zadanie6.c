#include <stdint.h>

int32_t pow_float(int32_t f, int32_t i) {
  int32_t s = f & 0x80000000;
  int32_t e = (f >> 23 & 255) - 127; /* wykładnik po odjęciu bias */
  uint32_t m = f & 0x007fffff;
  /* TODO */
  if (i >= 0) {
    if (e + i > 127) return s | 0x7F800000;
    return s | (e + i + 127) << 23 | m;
  } else {
    if (e + i < -150) return s | 0;
    if (e + i <= -127) return s | ((0x00800000 | m) >> -(e + i + 126));
    return s | (e + i + 127) << 23 | m;
  }
}