#include "FreeRTOS.h"
#include "task.h"
#include <avr/io.h>
#include <stdio.h>
#include "uart.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>
#include <queue.h>
#include <avr/interrupt.h>
int uart_transmit(char c, FILE *stream);
int uart_receive(FILE *stream);

FILE uart_file = FDEV_SETUP_STREAM(uart_transmit, uart_receive, _FDEV_SETUP_RW);
QueueHandle_t queuerecive;
QueueHandle_t queuetransmit;
void uart_init() {
  sei();
  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= _BV(U2X0);
#else
  UCSR0A &= ~(_BV(U2X0));
#endif
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
  UCSR0B = _BV(RXEN0) | _BV(TXEN0); /* Enable RX and TX */
  UCSR0B |= _BV(RXCIE0);
  queuerecive = xQueueCreate( 100, sizeof( char ) );
  queuetransmit = xQueueCreate( 100, sizeof( char ) );
}

int uart_transmit(char c, FILE *stream) {
  while(xQueueSend( queuetransmit, ( void * ) &c, ( TickType_t ) 0 ) == errQUEUE_FULL);
  UCSR0B |= _BV(UDRIE0);
  return 0;
}

int uart_receive(FILE *stream) {
  char val;
  while( xQueueReceive( queuerecive, &( val ), ( TickType_t ) 10 ) == errQUEUE_EMPTY ){

  }
    return val;
}

ISR(USART_RX_vect) 
{
  char c = UDR0;
  while(xQueueSendFromISR( queuerecive, ( void * ) &c, ( TickType_t ) 0 ) == errQUEUE_FULL){
  }
}

ISR(USART_TX_vect) 
{

}

ISR(USART_UDRE_vect) 
{
  char val;
  if( xQueueReceiveFromISR( queuetransmit, &( val ), ( TickType_t ) 10 ) == errQUEUE_EMPTY ){
    UCSR0B &= ~_BV(UDRIE0);
  }else
  {
    UDR0=val;
  }
}