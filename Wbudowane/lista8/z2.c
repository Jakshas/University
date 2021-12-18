/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <avr/io.h>


#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainLED_TASK_PRIORITY   10

#define mainSERIAL_TASK_PRIORITY 1

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vBlinkLed(void* pvParameters);

static void vSerial(void* pvParameters);
QueueHandle_t queue = NULL;
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
        uart_init();
    stdin = stdout = stderr = &uart_file;
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle serial_handle;
    queue = xQueueCreate( 10, sizeof(int8_t));

    xTaskCreate
        (
         vBlinkLed,
         "blink",
         300,
         NULL,
         mainLED_TASK_PRIORITY,
         &blink_handle
        );

    xTaskCreate
        (
         vSerial,
         "serial",
         300,
         NULL,
         mainSERIAL_TASK_PRIORITY,
         &serial_handle
        );

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
        uart_init();
    stdin = stdout = stderr = &uart_file;
    DDRB |= _BV(PB5);
    int8_t val;

    for ( ;; )
    {

        if (queue != NULL)
        {
            if( xQueueReceive( queue, &( val ), ( TickType_t ) 10 ) == pdPASS ){
                PORTB |= _BV(PB5);
                vTaskDelay((val * 1000) / portTICK_PERIOD_MS);
                PORTB &= ~_BV(PB5);
                vTaskDelay( 500 / portTICK_PERIOD_MS);
            }
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

    int8_t input;

    for ( ;; )
    {
        puts("Wpisz liczbe\r\n");
        scanf("%d",&input);
        printf("Podana liczba %d\r\n", input); 
        xQueueSend( queue, ( void * ) &input, ( TickType_t ) 0 );
    }
}
