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
    DDRC = 255;
    while (1)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 500; k++)
                {
                    PORTC = 1;
                    PORTD = table[j];
                    _delay_ms(1);
                    PORTC = 2;
                    PORTD = table[i];
                    _delay_ms(1);
                }
                
            }
        }
    }
}
