#include <avr/io.h>
#include <util/delay.h>

#define LED PORTD
#define LED_DDR DDRB
#define LED_PORT PORTB

int table[]={
    0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8
};

int main() {
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
    DDRD = 255;
    int i = 0;
    PORTC = 255;
    PORTD = table[1];
    while (1)
    {
        if (!(PINC & _BV(PC0)))
        {
            if (i == 0)
            {
                i=7;
            }else{
                i--;
            }
            _delay_ms(200);
        }
        if (!(PINC & _BV(PC1)))
        {
            if (i == 7)
            {
                i = 0;
            }else{
                i++;
            }
            _delay_ms(200);
        }
        if (!(PINC & _BV(2)))
        {
            i=0;
            _delay_ms(200);
        }
        PORTD = table[i];
    }
}