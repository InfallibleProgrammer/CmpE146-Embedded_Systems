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
#include <LabGPIO_0.h>
#include "LPC17xx.h"
#include "io.hpp"
#include <stdint.h>

//LPC_GPIO_TypeDef* port = (LPC_GPIO_TypeDef*) LPC_GPIO0;
uint8_t pin = 0;
uint8_t port = 1;

uint8_t pin1 = 9;
uint8_t port1 = 1;

uint8_t pin2 = 1;
uint8_t port2 = 0;

uint8_t pin3 = 1;
uint8_t port3 = 0;

uint8_t high = 1;
uint8_t readLevel = 0;
uint8_t output = 1;

int main (void)
{
	uint8_t x=0;
	uint8_t y=0;
	uint16_t z = 40000;
	y = (uint8_t)z;
	x = (uint8_t)(z>>8);
	printf("x: %i\n", x);
	printf("%i\n", z);
	printf("y: %i\n",y);
	printf("%i\n", z);
	return 0;
	// LabGPIO_0 AG(pin,port);
	// LabGPIO_0 AG1(pin1,port1);
	// LabGPIO_0 AG2(pin2, port2);
	// AG.setDirection(output);
	// AG1.setDirection(!output);
 //    while(1==1){
 //    	readLevel = AG1.getLevel();

 //    	if(readLevel){
	//     	AG.set(!high);
	//     	delay_ms(500);
 //    	}
 //    	else{
	//         AG.set(high);
	//         delay_ms(500);    		
 //    	}
 //    }
}
