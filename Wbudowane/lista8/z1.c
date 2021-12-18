/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>
#include <avr/delay.h>


#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainLED_TASK_PRIORITY   2

#define mainSERIAL_TASK_PRIORITY 1
#define mainREPEAT_TASK_PRIORITY 1
#define mainLINE_TASK_PRIORITY 1

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vBlinkLed(void* pvParameters);

static void vRepeatLed(void* pvParameters);
static void vLineLed(void* pvParameters);

static void vSerial(void* pvParameters);

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn int main(void)
 *
 * \brief Main function.
 *
 * \return
 ******************************************************************************/
int main(void)
{
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle serial_handle;
    xTaskHandle repeat_handle;
    xTaskHandle line_handle;

    // xTaskCreate
    //     (
    //      vBlinkLed,
    //      "blink",
    //      configMINIMAL_STACK_SIZE,
    //      NULL,
    //      mainLED_TASK_PRIORITY,
    //      &blink_handle
    //     );

    xTaskCreate
        (
         vRepeatLed,
         "repeat",
         300,
         NULL,
         mainREPEAT_TASK_PRIORITY,
         &repeat_handle
        );

    xTaskCreate
        (
         vLineLed,
         "line",
         300,
         NULL,
         mainLINE_TASK_PRIORITY,
         &line_handle
        );

    // xTaskCreate
    //     (
    //      vSerial,
    //      "serial",
    //      configMINIMAL_STACK_SIZE,
    //      NULL,
    //      mainSERIAL_TASK_PRIORITY,
    //      &serial_handle
    //     );

    // Start scheduler.
    vTaskStartScheduler();

    return 0;
}

/**************************************************************************//**
 * \fn static vApplicationIdleHook(void)
 *
 * \brief
 ******************************************************************************/
void vApplicationIdleHook(void)
{

}

/******************************************************************************
 * Private function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn static void vBlinkLed(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vBlinkLed(void* pvParameters)
{
    DDRB |= _BV(PB5);

    for ( ;; )
    {
        PORTB ^= _BV(PB5);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB

static void vRepeatLed(void* pvParameters)
{
    int8_t bufor[UINT8_MAX];
    BTN_PORT |= _BV(BTN);
    LED_DDR |= _BV(LED);
    uint8_t i = 0;
    uint8_t j = 0;
    for (;i<100;i++) {
        bufor[i] = 4;
    }
    for ( ;;i++,j++ ) {
        bufor[i] = BTN_PIN & _BV(BTN);
        if (bufor[j]>0)
        LED_PORT &= ~_BV(LED);
        else
        LED_PORT |= _BV(LED);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

static void vLineLed(void* pvParameters)
{
    UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
    DDRD = 255;
    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            PORTD &= 0;
            PORTD |= 1<<i;
            vTaskDelay(300 / portTICK_PERIOD_MS);
        }
        for (int i = 6; i > 0; i--)
        {
            PORTD &= 0;
            PORTD |= 1<<i;
            vTaskDelay(300 / portTICK_PERIOD_MS);
        }
    }
}

/**************************************************************************//**
 * \fn static void vSerial(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vSerial(void* pvParameters)
{
    uart_init();
    stdin = stdout = stderr = &uart_file;

    char input;

    for ( ;; )
    {
        puts("Hello World\r\n");
        input = getchar();
        printf("You wrote %c\r\n", input); 
    }
}
