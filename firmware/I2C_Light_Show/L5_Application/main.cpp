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
#include <stdint.h>
#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "tasks.hpp"
//#include "ADCDriver.h"
//#include "PWMDriver.h"
#include "LabGPIO.h"
#include "LabGPIOInterrupts.h"
#include "printf_lib.h"
#include "i2c_base.hpp"


//**********************Side Functions/Globals Here**********************
//one adc driver for all the LED colors
// ADCDriver rgb_ADC;

// i2c_base adcValue_I2c;

// //one driver for all the LED colors


// //Interrupt driver
// LabGPIOInterrupts gpio_intr_instance;


// //port pin setup to use in function.
// const uint16_t def_freq = 1000;

// //RGB power status
// uint8_t adc[3];

// // struct RGB {
// // 	float adc_value; //read adc value
// // } green, blue, red; //RGB struct for each RGB led

// float getDutyCycle(float adc_volt) {
// 	float dutyCycle = adc_volt * (100 / 3.3); //3.3 is VREF, returns the duty cycle
// 	return dutyCycle;
// }

// void c_eint3_handler(void)
// {
// 	gpio_intr_instance.handle_interrupt();
// }

// //**********************RTOS TASKS BELOW**********************

// void vRGB(void * pvParamaters)
// {	rgb_ADC.adcInitBurstMode();
// 	rgb_ADC.adcSelectPin(ADCDriver::ADC_PIN_0_26);
// 	rgb_ADC.adcSelectPin(ADCDriver::ADC_PIN_1_31);
// 	rgb_ADC.adcSelectPin(ADCDriver::ADC_PIN_1_30);
// 	while (1)
// 	{

// 		//Set ADC_value
// 		adc[0] = rgb_ADC.readADCVoltageByChannel(3);
// 		adc[1] = rgb_ADC.readADCVoltageByChannel(5);
// 		adc[2] = rgb_ADC.readADCVoltageByChannel(4);
// 		adcValue_I2c.writeRegisters(0xc0, 0x00, adc[], 0b11);

// 	}

// }

// void vDisplay(void * pvParameters)
// {
// 	while (1)
// 	{
// 		u0_dbg_printf("**********************ADC Values**********************\n");
// 		u0_dbg_printf("Green: %f\n", green.adc_value);
// 		u0_dbg_printf("Blue: %f\n", blue.adc_value);
// 		u0_dbg_printf("Red: %f\n", red.adc_value);
// 	}
// }
//bool I2C_Base::readRegisters(uint8_t deviceAddress, uint8_t firstReg, uint8_t* pData, uint32_t transferSize)
I2C2& I2C = I2C2::getInstance();
int main (void)
{
	uint8_t buffer[10] = {0};
	I2C.init(1);
	while (1)
	{
		I2C.writeRegisters(0xc0, 0x03, &buffer[0], 3);
		for (int i = 0; i < 3; i++) {
			buffer[i] = buffer[i] + 20;
			delay_ms(250);
		}
		for (int i = 6; i > 3; i--) {
			buffer[i] = buffer[i] - 20;
			delay_ms(250);
		}
		I2C.readRegisters(0xc0, 0x06, &buffer[6], 6);
		for (int i = 6; i < 9; i++) {
			u0_dbg_printf("Data: %x\n", buffer[i]);
			delay_ms(1000);
		}

	}
}

