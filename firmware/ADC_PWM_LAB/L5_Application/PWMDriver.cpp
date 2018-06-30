#include "PWMDriver.h"

const uint8_t powerUpBit = 6;
const uint8_t pClkBit = 12;
const uint8_t tcr_Pwm_Enable = 3;
const uint32_t MCU_clock = 48 * 1000000; //clock in hz(48Mhz)

PWMDriver::PWMDriver()
{

}

void PWMDriver::pwmSelectAllPins() //enables all PWM pins
{
	uint8_t bit_mask = 0;
	for (uint8_t i = 0; i < 6; i++)
	{
		bit_mask = i * 2; //since bitmask shifts every 2 bits.
		LPC_PINCON->PINSEL4 &= ~(0b11 << bit_mask);
		LPC_PINCON->PINMODE4 &= ~(0b11 << bit_mask);
		LPC_PINCON->PINSEL4 |= (0b01 << bit_mask);
		LPC_PINCON->PINMODE4 |= (0b11 << bit_mask);
	}
}

void PWMDriver::pwmSelectPin(PWMDriver::PWM_PIN pwm_pin_arg)
{
	uint8_t pin = 0;
	switch (pwm_pin_arg)
	{
	case (PWM_PIN_2_0):
		pin = 0;
		PWMDriver::pwmSelectPinCon(pin);
		break;
	case (PWM_PIN_2_1):
		pin = 1;
		PWMDriver::pwmSelectPinCon(pin);
		break;
	case (PWM_PIN_2_2):
		pin = 2;
		PWMDriver::pwmSelectPinCon(pin);
		break;
	case (PWM_PIN_2_3):
		pin = 3;
		PWMDriver::pwmSelectPinCon(pin);
		break;
	case (PWM_PIN_2_4):
		pin = 4;
		PWMDriver::pwmSelectPinCon(pin);
		break;
	case (PWM_PIN_2_5):
		pin = 5;
		PWMDriver::pwmSelectPinCon(pin);
		break;
	default:
		break;
	}
}

void PWMDriver::pwmSelectPinCon(uint8_t in_pin)
{
	uint32_t shift_bit = in_pin * 2;
	LPC_PINCON->PINSEL4 &= ~(0b11 << shift_bit);
	LPC_PINCON->PINMODE4 &= ~(0b11 << shift_bit);
	LPC_PINCON->PINSEL4 |= (0b01 << shift_bit);
	LPC_PINCON->PINMODE4 |= (0b11 << shift_bit);
}

void PWMDriver::setDuty0() //function to set all PWM channels to 0%
{
	setDutyCycle(PWM_PIN_2_0, 100);
	setDutyCycle(PWM_PIN_2_1, 100);
	setDutyCycle(PWM_PIN_2_2, 100);
	setDutyCycle(PWM_PIN_2_3, 100);
	setDutyCycle(PWM_PIN_2_4, 100);
	setDutyCycle(PWM_PIN_2_5, 100);
}

void PWMDriver::pwmInitSingleEdgeMode(uint32_t frequency_Hz)
{
	LPC_SC->PCONP |= (1 << powerUpBit); //power pwm is set to on
	LPC_SC->PCLKSEL0 &= ~(0b11 << pClkBit); //reset peri clock
	LPC_SC->PCLKSEL0 |= (1 << pClkBit); //set peri clock
	LPC_PWM1->MCR |= (1 << 1); // generates interrupt when MCR matches
	LPC_PWM1->PR  = 0; //resets prescale counter. Counts +1
	//every pclk cycle
	setFrequency(frequency_Hz);
	LPC_PWM1->PCR &= ~(0b11111 << 2); // 0 is single, 1 is double.
	LPC_PWM1->TCR |= (1 << 0); // bit 0 is counter. 1 enables count
	LPC_PWM1->TCR |= (1 << tcr_Pwm_Enable); //pwm mode is enabled
	LPC_PWM1->CTCR &= ~(0b1111 << 0); //enables the timer

	// Enable output on all six pwm channels
	LPC_PWM1->PCR |= (0b111111 << 9);

	setDuty0();
}

void PWMDriver::setDutyCycle(PWMDriver::PWM_PIN pwm_pin_arg, float duty_cycle_percentage)
{
	uint32_t rawDutyCycle = (LPC_PWM1->MR0 * duty_cycle_percentage);
	uint32_t dutyCycle = rawDutyCycle / 100;
	switch (pwm_pin_arg)
	{
	case PWM_PIN_2_0:
		LPC_PWM1->MR1 = dutyCycle; //set duty cycle value
		LPC_PWM1->LER |= (1 << 1); //Load Enable Register
		break;
	case PWM_PIN_2_1:
		LPC_PWM1->MR2 = dutyCycle;
		LPC_PWM1->LER |= (1 << 2);
		break;
	case PWM_PIN_2_2:
		LPC_PWM1->MR3 = dutyCycle;
		LPC_PWM1->LER |= (1 << 3);
		break;
	case PWM_PIN_2_3:
		LPC_PWM1->MR4 = dutyCycle;
		LPC_PWM1->LER |= (1 << 4);
		break;
	case PWM_PIN_2_4:
		LPC_PWM1->MR5 = dutyCycle;
		LPC_PWM1->LER |= (1 << 5);
		break;
	case PWM_PIN_2_5:
		LPC_PWM1->MR6 = dutyCycle;
		LPC_PWM1->LER |= (1 << 6);
		break;
	default:
		break;
	}
}

void PWMDriver::setFrequency(uint32_t frequency_Hz)
{
	const uint32_t frequency = MCU_clock / frequency_Hz;
	LPC_PWM1->MR0 = frequency; //save value into Match Register 0
	LPC_PWM1->LER |= (1 << 0); //Load Enable to laod match register 0
}
