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
#include "LabGPIOInterrupts.h"

void printA(void);
void akash();
//LabGPIOInterrupts* gpio1 = LabGPIOInterrupts::getInstance();
LabGPIOInterrupts gpio1;
int main (void)
{
    uint8_t pin = 0;
    uint8_t port = 0;
    gpio1.attachInterruptHandler(port, pin, akash, falling_edge);
    gpio1.init();
    isr_register(EINT3_IRQn, printA);
    while(1){
    }
}

void printA(void){
    gpio1.handle_interrupt();
}

void akash(){
    printf("I guess it worked???");
}