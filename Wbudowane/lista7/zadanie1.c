#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "i2c.h"

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

const uint8_t eeprom_addr = 0b10100000; 

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  i2cInit();
  #define i2cCheck(code, msg) \
    if ((TWSR & 0xf8) != (code)) { \
      printf(msg " failed, status: %.2x\r\n", TWSR & 0xf8); \
      i2cReset(); \
      continue; \
    }
  printf("Puc command write or read\r\n");
  while(1)
  {
    char command_buf[10];
    uint16_t adrr;
    uint8_t data;

    scanf("%s %d", command_buf, &adrr);
    printf("Received command %s; adrr=0x%d\r\n", command_buf, adrr);
    
    if(0 == strcmp(command_buf, "read")){
      i2cStart();
      i2cCheck(0x08, "I2C start");
      i2cSend(eeprom_addr | ((adrr & 0x100) >> 7));
      i2cCheck(0x18, "I2C EEPROM write request")
      i2cSend(adrr & 0xff);
      i2cCheck(0x28, "I2C EEPROM set address")
      i2cStart();
      i2cCheck(0x10, "I2C second start")
      i2cSend(eeprom_addr | 0x1 | ((adrr & 0x100) >> 7));
      i2cCheck(0x40, "I2C EEPROM read request")
      data = i2cReadNoAck();
      i2cStop();
      i2cCheck(0xf8, "I2C stop")
      printf("Read data: addr[0x%.3x] = 0x%x\r\n", adrr, data);
    }
    else if(0 == strcmp(command_buf, "write")){
      scanf("%d", &data); 
      printf("Assigning addr[0x%.3x] := 0x%x\r\n", adrr, data);
      i2cStart();
      i2cCheck(0x08, "I2C start")
      i2cSend(eeprom_addr | ((adrr & 0x100) >> 7));
      i2cCheck(0x18, "I2C EEPROM write request")
      i2cSend(adrr & 0xff);
      i2cCheck(0x28, "I2C EEPROM set address")
      i2cSend(data);
      i2cCheck(0x28, "I2C EEPROM write")
      i2cStop(); 
      i2cCheck(0xf8, "I2C stop")
    }else{
        printf("Puc command write or read\r\n");
    }
    
    printf("\r\n");

  }
}