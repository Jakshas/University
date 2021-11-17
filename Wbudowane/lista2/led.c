#include <avr/io.h>
#include <util/delay.h>

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB

int main() {
  int bufor[UINT8_MAX];
  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED);
  uint8_t i = 0;
  uint8_t j = 0;
  while (i<100) {
    bufor[i] = BTN_PIN & _BV(BTN);
    _delay_ms(10);
    i++;
  }
  while (1) {
    bufor[i] = BTN_PIN & _BV(BTN);
    if (bufor[j]>0)
      LED_PORT &= ~_BV(LED);
    else
      LED_PORT |= _BV(LED);
    _delay_ms(10);
    i++;
    j++;
  }
}