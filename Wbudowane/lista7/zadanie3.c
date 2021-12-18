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

const uint8_t eeprom_addr = 0b11010000;


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

  while(1)
  {
    char cmd[10];
    printf("Podaj komende\r\n");
    scanf("%s ", cmd);
    printf("%s ", cmd);
    if(0 == strcmp(cmd, "date"))
    {
      uint8_t day, month, year;
      while(1)
      {
        i2cStart();
        i2cCheck(0x08, "I2C start");
        i2cSend(eeprom_addr);
        i2cCheck(0x18, "I2C EEPROM write request")
        i2cSend(0x04);
        i2cCheck(0x28, "I2C EEPROM set address")
        i2cStart();
        i2cCheck(0x10, "I2C second start")
        i2cSend(eeprom_addr | 1);
        day = i2cReadAck();
        i2cCheck(0x50, "I2C EEPROM read request")
        month = i2cReadAck();
        i2cCheck(0x50, "I2C EEPROM read request")
        year = i2cReadNoAck();
        i2cCheck(0x58, "I2C EEPROM read request")
        i2cStop();
        i2cCheck(0xf8, "I2C stop")
        break;
      }
      int8_t century;
      if(month & 0x80){
        century = 0x21;
      }else
      {
        century = 0x20;
      }
      
      printf("%.2x-%.2x-%.2x%.2x\r\n", day, month & 0x1f, century, year);
    }

    if(0 == strcmp(cmd, "time"))
    {
      uint8_t seconds, minutes, hours;
      while(1)
      {
        i2cStart();
        i2cCheck(0x08, "I2C start");
        i2cSend(eeprom_addr);
        i2cCheck(0x18, "I2C EEPROM write request")
        i2cSend(0x0);
        i2cCheck(0x28, "I2C EEPROM set address")
        i2cStart();
        i2cCheck(0x10, "I2C second start")
        i2cSend(eeprom_addr | 1);
        seconds = i2cReadAck();
        i2cCheck(0x50, "I2C EEPROM read request")
        minutes = i2cReadAck();
        i2cCheck(0x50, "I2C EEPROM read request")
        hours = i2cReadNoAck();
        i2cCheck(0x58, "I2C EEPROM read request")
        i2cStop();
        i2cCheck(0xf8, "I2C stop")
        break;
      }
      printf("%.2x:%.2x:%.2x\r\n", hours, minutes, seconds);
    }

    if(0 == strcmp(cmd, "set"))
    {
      scanf("%s ", cmd);
      printf("%s ", cmd);
      if(0 == strcmp(cmd, "date"))
      {
        uint8_t day, month, century, year;
        scanf("%2hhx-%2hhx-%2hhx%2hhx ", &day, &month, &century, &year);
        if(century == 0x21){
          century = 0x80;
        }else
        {
          century = 0;
        }
      
        while(1)
        {
          i2cStart();
          i2cCheck(0x08, "I2C start in write")
          i2cSend(eeprom_addr | 0);
          i2cCheck(0x18, "I2C EEPROM write request in write")
          i2cSend(0x04);
          i2cCheck(0x28, "I2C EEPROM set address in write")
          i2cSend(day);
          i2cCheck(0x28, "I2C EEPROM write")
          i2cSend(month | century);
          i2cCheck(0x28, "I2C EEPROM write")
          i2cSend(year);
          i2cCheck(0x28, "I2C EEPROM write")
          i2cStop();
          i2cCheck(0xf8, "I2C stop")
          break;
        }
        printf("date set\r\n");
       }

      if(0 == strcmp(cmd, "time"))
      {
        uint8_t seconds, minutes, hours;
        scanf("%2hhx:%2hhx:%2hhx ", &hours, &minutes, &seconds);
        while(1)
        {
          i2cStart();
          i2cCheck(0x08, "I2C start in write")
          i2cSend(eeprom_addr | 0);
          i2cCheck(0x18, "I2C EEPROM write request in write")
          i2cSend(0);
          i2cCheck(0x28, "I2C EEPROM set address in write")
          i2cSend(seconds);
          i2cCheck(0x28, "I2C EEPROM write")
          i2cSend(minutes);
          i2cCheck(0x28, "I2C EEPROM write")
          i2cSend(hours);
          i2cCheck(0x28, "I2C EEPROM write")
          i2cStop();
          i2cCheck(0xf8, "I2C stop")
          break;
        }
        printf("time set\r\n");
      }
    }
    printf("\r\n");
  }
}