#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <avr/delay.h>
#include "sound.h"
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

void spi_init(){
    // ustaw piny MOSI, SCK i ~SS jako wyjścia
    DDRB |= _BV(DDB3) | _BV(DDB5) | _BV(DDB2);
    // włącz SPI w trybie master z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR1);
}

// transfer jednego bajtu
uint8_t spi_transfer(uint8_t data){
    // rozpocznij transmisję
    SPDR = data;
    // czekaj na ukończenie transmisji
    while (!(SPSR & _BV(SPIF)));
    // wyczyść flagę przerwania
    SPSR |= _BV(SPIF);
    // zwróć otrzymane dane
    return SPDR;
}

//Timer 0 init
void timer_init(){
    TCCR0A |= _BV(WGM01);
    TCCR0B |= _BV(CS01);
    TIMSK0 |= _BV(OCIE0A);
    OCR0A=124;
}

volatile uint16_t i=0;

ISR(TIMER0_COMPA_vect){
    if(i>=tablen){
        i=0;
        _delay_ms(1000);
    } 
    uint8_t data=~pgm_read_word(&tab[i]);
    i++;
    PORTB &= ~_BV(DDB2);
    spi_transfer(0b01110000|(data>>4));
    spi_transfer(data<<4);
    PORTB |= _BV(DDB2);
}

int main(){
    // zainicjalizuj UART
    uart_init();
    // skonfiguruj strumienie wejścia/wyjścia
    fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
    stdin = stdout = stderr = &uart_file;
    // zainicjalizuj SPI
    spi_init();
    timer_init();
    sei();
    PORTB |= _BV(DDB2);
    while(1) {
  }
}