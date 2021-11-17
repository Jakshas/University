#include <avr/io.h>
#include <util/delay.h>

#define LED PORTD
#define LED_DDR DDRB
#define LED_PORT PORTB

int table[]={
    192,
    249, 
    164,
    176,
    153,
    146,
    130,
    248,
    128,
    144
};

int main() {
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
    DDRD = 255;
    while (1)
    {
        for (int i = 0; i < 10; i++)
        {
            PORTD &= 0;
            PORTD |= ~table[i];
            _delay_ms(1000);
        }
    }
}