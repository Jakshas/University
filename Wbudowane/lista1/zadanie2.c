#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB
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

char * encode(const char * str){
    const char * word = ""; 
    for (;; ++str)
    {
        char c = *str;
        if (c == '\0'){
        word = strcat(word,"\0");
        break;
        }
        word = strcat(word,character[c - 'a']);
        word = strcat(word," ");
    }
    return word;
}

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program testowy
  printf("Podaj text do translacji(max 10 znaków):\r\n");
  LED_DDR |= _BV(LED);
  while(1) {
    char text[10];
    scanf("%s",&text);
    for(int i = 0; text[i]; i++){
      text[i] = tolower(text[i]);
    }
    char morse[100]; 
    printf("%s",text);
    for (int i = 0,g = 0;i<100; i++,g++)
    {
        char c = text[g];
        if (c == '\0'){
        morse[i] = '\0';
        break;
        }
        for (int j = 0; j < strlen(character[c - 'a']); j++,i++)
        {
          morse[i] = character[c - 'a'][j]; 
        }
        morse[i] = ' ';
    }
    for (int i = 0;i<100; i++)
    {
      char c = morse[i];
      if (c == '\0'){
        break;
      }
      if (c == ' ')
      {
        LED_PORT &= ~_BV(LED);
        _delay_ms(1000);
      }
      if (c == '.')
      {
        LED_PORT |= _BV(LED);
        _delay_ms(500);
      }
      if (c == '-')
      {
        LED_PORT |= _BV(LED);
        _delay_ms(1500);
      }        
      LED_PORT &= ~_BV(LED);
      _delay_ms(200);
    }
  }
}
