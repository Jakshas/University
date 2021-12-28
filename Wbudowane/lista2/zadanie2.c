#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <util/delay.h>
#include <string.h>

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
  // czekaj aż transmiter gotowy
  while(!(UCSR0A & _BV(UDRE0)));
  UDR0 = data;
  return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

FILE uart_file;
static const char *character[] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
};

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program testowy
  printf("Wpisz morsa\r\n");
    BTN_PORT |= _BV(BTN);
    LED_DDR |= _BV(LED);
    char slowo[5];
    int pozycja=0,j=0;
    while(1) {
        while (BTN_PIN & _BV(BTN))
        {
            j++;
            _delay_ms(10);
            if (j>200)
            {
                slowo[pozycja]='\0';
                int czy_znaleziono = 0;
                for (int i = 0; i < 26; i++)
                {
                    if (strcmp(slowo,character[i])==0)
                    {
                        printf("%c",(i+'A'));
                        czy_znaleziono=1;
                        break;
                    }
                }
                if (czy_znaleziono = 0)
                {
                    printf("Wzór nie pasuje.\r\n");
                }
                for (int i = 0; i < 5; i++)
                {
                    slowo[i]=' ';
                }
                pozycja = 0;
                j = 0;
                break;
            }
        }
        while (!(BTN_PIN & _BV(BTN)))
        {
            int i = 1;
            _delay_ms(10);
            while (!(BTN_PIN & _BV(BTN)))
            {
                _delay_ms(10);
                i++;
                if (i>100)
                {
                    LED_PORT |= _BV(LED);
                }
            }
            LED_PORT &= ~_BV(LED);
            if (i > 100)
            {
                slowo[pozycja] = '_';
            }else
            {
                slowo[pozycja] = '.';
            }
            pozycja++;
        }
  }
}