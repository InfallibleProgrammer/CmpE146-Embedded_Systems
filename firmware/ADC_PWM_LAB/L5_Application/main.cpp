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
#include "ADCDriver.h"
#include "PWMDriver.h"
#include "LabGPIO.h"
#include "LabGPIOInterrupts.h"
#include "printf_lib.h"


//**********************Side Functions/Globals Here**********************
//one adc driver for all the LED colors
ADCDriver rgb_ADC;

//one driver for all the LED colors
PWMDriver rgb_PWM;

//Interrupt driver
LabGPIOInterrupts gpio_intr_instance;


//port pin setup to use in function.
const uint16_t def_freq = 1000;

//RGB power status
bool on_Mode = true;

struct RGB {
	float adc_value; //read adc value
	float pwm_value; //takes pwm to set pwm
} green, blue, red; //RGB struct for each RGB led

void vCall_Back() //used for ISR button trigger.
{
	if (on_Mode == true) {
		on_Mode = false;
	}
	else if (on_Mode == false) {
		on_Mode = true;
	}
}
float getDutyCycle(float adc_volt) {
	float dutyCycle = adc_volt * (100 / 3.3); //3.3 is VREF, returns the duty cycle
	return dutyCycle;
}

void c_eint3_handler(void)
{
	gpio_intr_instance.handle_interrupt();
}

//**********************RTOS TASKS BELOW**********************

void vRGB(void * pvParamaters)
{	rgb_ADC.adcInitBurstMode();
	rgb_PWM.pwmInitSingleEdgeMode(100);
	rgb_ADC.adcSelectPin(ADCDriver::ADC_PIN_0_26);
	rgb_ADC.adcSelectPin(ADCDriver::ADC_PIN_1_31);
	rgb_ADC.adcSelectPin(ADCDriver::ADC_PIN_1_30);
	rgb_PWM.pwmSelectPin(PWMDriver::PWM_PIN_2_0);
	rgb_PWM.pwmSelectPin(PWMDriver::PWM_PIN_2_1);
	rgb_PWM.pwmSelectPin(PWMDriver::PWM_PIN_2_2);
	rgb_PWM.setFrequency(def_freq);
	while (1)
	{
		if (on_Mode == 1)
		{
			//Set ADC_value
			green.adc_value = rgb_ADC.readADCVoltageByChannel(3);
			blue.adc_value = rgb_ADC.readADCVoltageByChannel(5);
			red.adc_value = rgb_ADC.readADCVoltageByChannel(4);

			//set the duty cycle now
			green.pwm_value = getDutyCycle(green.adc_value);
			blue.pwm_value = getDutyCycle(blue.adc_value);
			red.pwm_value = getDutyCycle(red.adc_value);
			rgb_PWM.setDutyCycle(PWMDriver::PWM_PIN_2_0, green.pwm_value);
			rgb_PWM.setDutyCycle(PWMDriver::PWM_PIN_2_1, blue.pwm_value);
			rgb_PWM.setDutyCycle(PWMDriver::PWM_PIN_2_2, red.pwm_value);
		}
		else if (on_Mode == 1)
		{
			green.pwm_value = 100;
			blue.pwm_value = 100;
			red.pwm_value = 100;
			rgb_PWM.setDutyCycle(PWMDriver::PWM_PIN_2_0, green.pwm_value);
			rgb_PWM.setDutyCycle(PWMDriver::PWM_PIN_2_1, blue.pwm_value);
			rgb_PWM.setDutyCycle(PWMDriver::PWM_PIN_2_2, red.pwm_value);
		}

	}

}

void vDisplay(void * pvParameters)
{
	while (1)
	{
		u0_dbg_printf("**********************ADC Values**********************\n");
		u0_dbg_printf("Green: %f\n", green.adc_value);
		u0_dbg_printf("Blue: %f\n", blue.adc_value);
		u0_dbg_printf("Red: %f\n", red.adc_value);
		u0_dbg_printf("**********************DutyCycle Values**********************\n");
		u0_dbg_printf("Green: %f\n", green.pwm_value);
		u0_dbg_printf("Blue: %f\n", blue.pwm_value);
		u0_dbg_printf("Red: %f\n", red.pwm_value);
		vTaskDelay(1000);
	}
}

int main (void)
{
	uint8_t pin = 0;
	gpio_intr_instance.init();
	//Task creation for RGB
	xTaskCreate(vRGB, "vRGB", 2048, NULL, 3, NULL);
	scheduler_add_task(new terminalTask(PRIORITY_HIGH));
	//Task Creation for printing out info;
	xTaskCreate(vDisplay, "vDisplay", 2048, NULL, 3, NULL);
	scheduler_add_task(new terminalTask(PRIORITY_HIGH));
	//Setup GPIO port for interrupt;
	gpio_intr_instance.attachInterruptHandler(pin, pin, vCall_Back, rising_edge); //GPIO 0.0
	isr_register(EINT3_IRQn, c_eint3_handler);
	vTaskStartScheduler();
}

