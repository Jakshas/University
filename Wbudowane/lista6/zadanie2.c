#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <avr/interrupt.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

FILE uart_file;

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

char buffer1[UINT8_MAX];
volatile uint8_t i1 = 0;  
volatile uint8_t i2 = 1; 
char buffer2[UINT8_MAX];
volatile uint8_t o1 = 0;
volatile uint8_t o2 = 1;

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
    while ((i2==i1)||(i2==UINT8_MAX&&i1<1));
    buffer1[i2]=data;
    i2++;
    if ((i1==UINT8_MAX-1&&i2==1)||i1+2 == i2) 
        UCSR0B |= _BV(UDRIE0);
    return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
    while (o1+1==o2||(o1==UINT8_MAX-1&&o2==0));
    o1++;
    return buffer2[o1];
}



ISR(USART_RX_vect) 
{
    buffer2[o2]=UDR0;
    o2++;
}

ISR(USART_TX_vect) 
{
}

ISR(USART_UDRE_vect) 
{
    if( (i1==UINT8_MAX-1&&i2==0) ||i1+1==i2){
        UCSR0B &= ~_BV(UDRIE0);
        return;
    }
    i1++;
    UDR0=buffer1[i1];
}

int main()
{
    sei();
    // zainicjalizuj UART
    uart_init();
    UCSR0B |= _BV(RXCIE0);
    // skonfiguruj strumienie wejścia/wyjścia
    fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
    stdin = stdout = stderr = &uart_file;
    // program testowy
    printf("Hello world!\r\n");
    while(1) {
        char a[250];
        scanf("%s", &a);
        printf("Odczytano: %s\r\n", a);
    }
}
