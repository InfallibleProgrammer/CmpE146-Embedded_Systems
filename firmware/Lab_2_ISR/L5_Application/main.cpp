/*
 *     SocialLedge.com - Copyright (C) 2013
 *
 *     This file is part of free software framework for embedded processors.
 *     You can use it and/or distribute it as long as this copyright header
 *     remains unmodified.  The code is free for personal use and requires
 *     permission to use in a commercial product.
 *
 *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *     You can reach the author of this software at :
 *          p r e e t . w i k i @ g m a i l . c o m
 */

/**
 * @file
 * @brief This is the application entry point.
 * 			FreeRTOS and stdio printf is pre-configured to use uart0_min.h before main() enters.
 * 			@see L0_LowLevel/lpc_sys.h if you wish to override printf/scanf functions.
 *
 */
#include <stdio.h>
#include "tasks.hpp"
#include "utilities.h"
#include "io.hpp"
#include "LabGPIO.h"
#include <stdint.h>
#include "LabGPIOInterrupts.h"

SemaphoreHandle_t xSemaphore;

void vControlLED( void * pvParameters )
{
    /* Get Parameter */
    uint32_t addr = (uint32_t)(pvParameters);
    uint8_t pin = (uint8_t)(addr); //lowerbits
    uint8_t port = (uint8_t)(addr >> 16); //upperbits
    LabGPIO led10(pin,port);
    led10.setDirection(1);

    while(1)
    {
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY))
        {
            led10.set(0);
            vTaskDelay(100);
            led10.set(1); 
        }   
    }
}

void vCall_Back( )
{
    xSemaphoreGive(xSemaphore);
}



LabGPIOInterrupts gpio_intr_instance;

void c_eint3_handler(void)
{
    gpio_intr_instance.handle_interrupt();
}


int main(void)
{
    xSemaphore = xSemaphoreCreateBinary();
    gpio_intr_instance.init();
    int pin = 0;
    uint32_t led = 0x00010000; //4 most significant bits is port, 4 least significant bits are pin. Pin 1, port 0(led)
    gpio_intr_instance.attachInterruptHandler(pin,pin, vCall_Back, rising_edge);
    xTaskCreate(vControlLED, "vLed", 1024, ( void * ) led, 3, NULL );
    scheduler_add_task(new terminalTask(PRIORITY_HIGH));
    isr_register(EINT3_IRQn, c_eint3_handler);
    scheduler_start();
}

