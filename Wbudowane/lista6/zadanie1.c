#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <inttypes.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

volatile uint8_t data;

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);

  UCSR0B |= _BV(RXCIE0);
  UCSR0B |= _BV(TXCIE0);
}
ISR(USART_RX_vect){
  data=UDR0;
  UDR0 = data;
}

ISR(USART_TX_vect){
}

int main(int argc, char const *argv[])
{
    uart_init();
    sei();
    set_sleep_mode(SLEEP_MODE_IDLE);
    while (1)
    {
      sleep_mode();
    }
    return 0;
}
