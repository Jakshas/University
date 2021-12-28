#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

#define BUZZ PB5
#define BUZZ_DDR DDRB
#define BUZZ_PORT PORTB

#define TONE(step, delay) \
    for (uint16_t i = 0; i < (uint32_t)1000 * (delay) / (step) / 2; i++) { \
      BUZZ_PORT |= _BV(BUZZ); \
      for (int j = 0; j < step; j++) \
      _delay_us(1); \
      BUZZ_PORT &= ~_BV(BUZZ); \
      for (int j = 0; j < step; j++)\
      _delay_us(1); \
    }

#define cala 100
#define pol 50
#define cwierc 25


static const int8_t nuty[30][2] PROGMEM = {
  {'G','C'},
  {'E','C'},
  {'E','C'},
  {'F','C'},
  {'D','C'},
  {'D','C'},
  {'C','P'},
  {'E','P'},
  {'G','P'},
  {'P','P'},

  {'G','C'},
  {'E','C'},
  {'E','C'},
  {'F','C'},
  {'D','C'},
  {'D','C'},
  {'C','P'},
  {'E','P'},
  {'C','P'},
  {'P','P'},

  {'G','C'},
  {'E','C'},
  {'E','C'},
  {'F','C'},
  {'D','C'},
  {'D','C'},
  {'C','P'},
  {'E','P'},
  {'G','P'},
};

int main() {
  BUZZ_DDR |= _BV(BUZZ);
  while (1) {
    for (uint8_t i = 0; i < sizeof(nuty); i++){
      int16_t liczba = 0;
      switch (pgm_read_byte(&nuty[i][0]))
      {
      case 'C':
        liczba = 131;
        break;
      case 'D':
        liczba = 147;
        break;
      case 'E':
        liczba = 165;
        break;
      case 'F':
        liczba = 175;
        break;
      case 'G':
        liczba = 196;
        break;
      case 'A':
        liczba = 220;
        break;
      case 'H':
        liczba = 247;
        break;
      default:
        break;
      }
      int16_t dlugosc = 500;
      switch (pgm_read_byte(&nuty[i][1]))
      {
      case 'C':
        dlugosc = 400;
        break;
      case 'P':
        dlugosc = 200;
        break;
      case 'Q':
        dlugosc = 100;
        break;
      default:
        break;
      }
      if (liczba == 0)
      {
        _delay_ms(400);
      }else{
        int16_t a = 2000/liczba;
        TONE(a*dlugosc/2,dlugosc);
        _delay_ms(100);
      } 
    }
  }
}