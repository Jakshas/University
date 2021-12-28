/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "mpu_wrappers.h"
#include <avr/io.h>
#include <avr/interrupt.h>


#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/


#define func_TASK_PRIORITY 1

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void func(void* pvParameters);


/******************************************************************************
 * Public function definitions.
 ******************************************************************************/

SemaphoreHandle_t mutex_read, mutex_adc;

void adc_init()
{
  ADMUX = _BV(REFS0); // ref wyjscia na ADC0
  DIDR0 = _BV(ADC0D) | _BV(ADC1D) | _BV(ADC2D); // włączamy A0 A1 A2
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADIE); // ADC interrupt enable
  ADCSRA |= _BV(ADEN); // włącz ADC
}


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
    xTaskHandle adc0_handle;
    xTaskHandle adc1_handle;
    xTaskHandle adc2_handle;
    mutex_adc = xSemaphoreCreateMutex();
    mutex_read = xSemaphoreCreateMutex();
    adc_init();
    sei();
    
    xTaskCreate
        (
         func,
         "adc0",
         configMINIMAL_STACK_SIZE,
         0,
         func_TASK_PRIORITY,
         &adc0_handle
        );

    xTaskCreate
        (
         func,
         "adc1",
         configMINIMAL_STACK_SIZE,
         1,
         func_TASK_PRIORITY,
         &adc1_handle
        );

    xTaskCreate
        (
         func,
         "adc2",
         configMINIMAL_STACK_SIZE,
         2,
         func_TASK_PRIORITY,
         &adc2_handle
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
uint16_t readADC(uint8_t mux)
{
    ADMUX = _BV(REFS0) | mux;
    xSemaphoreTake(mutex_adc, portMAX_DELAY);
    ADCSRA |= _BV(ADSC);
    return ADC;
}

ISR(ADC_vect)
{
  xSemaphoreGiveFromISR(mutex_adc, NULL); 
}


/******************************************************************************
 * Private function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn static void vSerial(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void func(void* pvParameters)
{
    uart_init();
    stdin = stdout = stderr = &uart_file;
    uint8_t port = (uint8_t)pvParameters;
    char pstr[] = "Port ";
    char val[5];
    while (1)
    {
        xSemaphoreTake(mutex_read, portMAX_DELAY);
        for (int8_t i = 0; i < 5; i++)
        {
            putchar(pstr[i]);
        }
        putchar('0'+port);
        putchar(':');
        utoa(readADC(port),val,10);
        for (int8_t i = 0; i < 5; i++)
        {
            putchar(val[i]);
        }
        putchar('|');
        xSemaphoreGive(mutex_read);
        vTaskDelay(((port*250)+2000) / portTICK_PERIOD_MS);
    }

}