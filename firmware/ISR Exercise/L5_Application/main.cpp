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
 */

#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "lpc_isr.h"
#include "printf_lib.h"

void interrupt_callback(void) {
    //clear interrupt
    //maybe u0_dbg_printf() or blink and LED here to test your ISR
    if (LPC_GPIOINT->IO0IntStatR & ((1 << 0) = 1)) {
        u0_dbg_printf("Inside ISR");
    }
    LPC_GPIOINT0->IO0INTClr |= (1 << 0);
}

int main (void)
{
    LPC_PINCON->PINSEL0 &= ~(3 << 0); //bits 0:1 is 00 for PINSEL0 Register
    printf("PINSEL0 Register: %p", LPC_PINCON->PINSEL0);
    LPC_GPIO0->FIODIR &= !(1 << 0);
    printf("PINSEL0 Register: %p", LPC_GPIO0->FIODIR);
    LPC_GPIOINT->IO0IntEnR |= (1 << 0);

    NVIC_EnableIRQ(EINT3_IRQn);
    isr_register(EINT3_IRQn, interrupt_callback);
}
