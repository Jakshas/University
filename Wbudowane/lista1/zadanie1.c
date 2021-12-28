#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>

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

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program testowy
  int typ=0;
  printf("Jakiego typu liczby chcesz dodać? 1-int8, 2-int16, 3-int32, 4-int64, 5-float\r\n");
  scanf("%d",&typ);
  printf("Podaj dwie liczby:\r\n");
  int8_t a1 ,b1;
  int16_t a2 ,b2;
  int32_t a3 ,b3;
  int64_t a4 ,b4;
  float a5 ,b5;
  int8_t wyn1;
  int16_t wyn2;
  int32_t wyn3;
  int64_t wyn4;
  float wyn5;
  switch (typ)
  {
    case 1:
      scanf("%"SCNd8, &a1);
      scanf("%"SCNd8, &b1);
        wyn1 = a1 + b1;
        printf("%hhd\r\n",wyn1);
        wyn1 = a1 - b1;
        printf("%hhd\r\n",wyn1);
        wyn1 = a1 * b1;
        printf("%hhd\r\n",wyn1);
        wyn1 = a1 / b1;
        printf("%hhd\r\n",wyn1);
      break;
    case 2:
      scanf("%"SCNd16, &a2);
      scanf("%"SCNd16, &b2);
        wyn2 = a2 + b2;
        printf("%hd\r\n",wyn2);
        wyn2 = a2 - b2;
        printf("%hd\r\n",wyn2);
        wyn2 = a2 * b2;
        printf("%hd\r\n",wyn2);
        wyn2 = a2 / b2;
        printf("%hd\r\n",wyn2);
      break;
    case 3:
      scanf("%"SCNd32, &a3);
      scanf("%"SCNd32, &b3);
        wyn3 = a3 + b3;
        printf("%ld\r\n",wyn3);
        wyn3 = a3 - b3;
        printf("%ld\r\n",wyn3);
        wyn3 = a3 * b3;
        printf("%ld\r\n",wyn3);
        wyn3 = a3 / b3;
        printf("%ld\r\n",wyn3);
      break;
    case 4:
      scanf("%lld", &a4);
      scanf("%lld", &b4);
        wyn4 = a4 + b4;
        printf("%lld\r\n",wyn4);
        wyn4 = a4 - b4;
        printf("%lld\r\n",wyn4);
        wyn4 = a4 * b4;
        printf("%lld\r\n",wyn4);
        wyn4 = a4 / b4;
        printf("%lld\r\n",wyn4);
      break;
    case 5:
      scanf("%f", &a5);
      scanf("%f", &b5);
        wyn5 = a5 + b5;
        printf("%f\r\n",wyn5);
        wyn5 = a5 - b5;
        printf("%f\r\n",wyn5);
        wyn5 = a5 * b5;
        printf("%f\r\n",wyn5);
        wyn5 = a5 / b5;
        printf("%f\r\n",wyn5);
      break;
  default:
      break;
  }

  while(1) {
    int16_t a = 1;
    scanf("%"SCNd16, &a);
    printf("Odczytano: %"PRId16"\r\n", a);
  }
}
