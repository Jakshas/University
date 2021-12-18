#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "i2c.h"

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem


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

int uart_transmit(char data, FILE *stream)
{
  // czekaj aż transmiter gotowy
  while(!(UCSR0A & _BV(UDRE0)));
  UDR0 = data;
  return 0;
}

int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

FILE uart_file;

const uint8_t eeprom_addr = 0xa0;

int main()
{
  uart_init();
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
    printf("Put command write or read\r\n");
    scanf("%s ", cmd);
    printf("Received command %s\r\n", cmd);
    
    if(0 == strcmp(cmd, "read"))
    {
      uint16_t addr;
      uint8_t len; 
      scanf("%x %hhx", &addr, &len);
      uint8_t checksum = (addr >> 8) + (uint8_t)(addr) + len;
      printf(":%.2x%.4x00", len, addr);
      
      while(1)
      {
        i2cStart();
        i2cCheck(0x08, "I2C start in read");
        i2cSend(eeprom_addr | ((addr & 0x100) >> 7));
        i2cCheck(0x18, "I2C EEPROM write request")
        i2cSend(addr & 0xff);
        i2cCheck(0x28, "I2C EEPROM set address")
        i2cStart();
        i2cCheck(0x10, "I2C second start")
        i2cSend(eeprom_addr | ((addr & 0x100) >> 7) | 1);
        i2cCheck(0x40, "I2C EEPROM read request")
        break;
      }
      for(uint8_t i = 0; i < len; i++)
      {
        uint8_t byte;
        if(i == len - 1)
        {
          byte = i2cReadNoAck();
          i2cCheck(0x58, "I2C EEPROM read")
        }
        else
        {
          byte = i2cReadAck();
          i2cCheck(0x50, "I2C EEPROM read")
        }
        checksum += byte;
        printf("%.2x", byte);
      }
      while(1)
      {
        i2cStop();
        i2cCheck(0xf8, "I2C stop")
        break;
      }
      checksum = -checksum;
      printf("%.2x\r\n\r\n", checksum);
    }
    else if(0 == strcmp(cmd, "write"))
    {
      uint8_t byten;
      uint16_t addr;
      uint8_t type, checksum;
      while(1)
      {
        char c = getchar();
        if(':' != c)
          continue;
        scanf("%2hhx%4x%2hhx", &byten, &addr, &type);
        printf(":%2hhx%4x%2hhx", byten, addr, type);
        uint8_t new_checksum = byten + (addr >> 8) + (uint8_t)(addr) + type;
        uint8_t buf[byten];
        if(1 == type)
        {
          int8_t mode;
          scanf("%2hhx",&mode);
          break;
        }
        if(0 != type)
          break;
        for(uint16_t i = 0; i < byten; i++)
        {
          uint8_t data;
          scanf("%2hhxx", &data);
          printf("%.2hhxx", data);
          new_checksum += data;
          buf[i] = data;
        }
        scanf("%2hhx", &checksum);
        new_checksum = -new_checksum;
        if(checksum != new_checksum)
        {
          printf("checksum mismatch 0x%x vs 0x%x\r\n", new_checksum, checksum);
          continue;
        }
        while(1)
        {
          i2cStart();
          i2cCheck(0x08, "I2C start in write")
          i2cSend(eeprom_addr | ((addr ) & 0x100) >> 7);
          i2cCheck(0x18, "I2C EEPROM write request in write")
          i2cSend((addr )& 0xff);
          i2cCheck(0x28, "I2C EEPROM set address in write")
          break;
        }
        for(uint16_t i = 0; i < byten;i++)
        {
            i2cSend(buf[i]);
            i2cCheck(0x28, "I2C EEPROM write")
        }
        i2cStop();
        i2cCheck(0xf8, "I2C stop")
        printf("record write done\r\n");
      }
      printf("write end\r\n\r\n");
    }
  }
}