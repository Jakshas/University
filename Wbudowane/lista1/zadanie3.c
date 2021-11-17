#include <avr/io.h>
#include <util/delay.h>

#define LED PORTD
#define LED_DDR DDRB
#define LED_PORT PORTB

int main() {
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
    DDRD = 255;
    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            PORTD &= 0;
            PORTD |= 1<<i;
            _delay_ms(1000);
        }
        for (int i = 6; i > 0; i--)
        {
            PORTD &= 0;
            PORTD |= 1<<i;
            _delay_ms(1000);
        }
    }
}