#include "DACDriver.h"

const float VREF = 3.3; //Reference voltage
LPC_DAC_TypeDef *current_dac;

DACDriver::DACDriver()
{

}
DACDriver::~DACDriver()
{

}

void DACDriver::initDAC(DAC_PIN dac_pin, bool mA_350)
{
	BIT(LPC_SC->PCLKSEL0).b23_22 = 0b01;
	if (mA_350 == 1)
	{
		printf("**** I AM HERE MOFO****\n");
		current_dac->DACR &= ~(1 << 16);
		current_dac->DACR |= (1 << 16);
		printf("WHY AM I NOT GOING HERE");
	}
	else
	{
		current_dac->DACR &= ~(1 << 16);
		current_dac->DACR |= (0 << 16);
	}
	switch (dac_pin)
	{
	case (DAC_PIN_0_25):
		BIT(LPC_PINCON->PINSEL1).b19_18 = 0b01;
		BIT(LPC_PINCON->PINMODE1).b19_18 = 0b11;
		printf("I AM HERE");
		break;
	case (DAC_PIN_0_26):
		BIT(LPC_PINCON->PINSEL1).b21_20 = 0b01;
		BIT(LPC_PINCON->PINMODE1).b21_20 = 0b11;
		break;
	case (DAC_PIN_1_30):
		BIT(LPC_PINCON->PINSEL3).b29_28 = 0b11;
		BIT(LPC_PINCON->PINMODE3).b29_28 = 0b11;
		break;
	case (DAC_PIN_1_31):
		BIT(LPC_PINCON->PINSEL3).b31_30 = 0b11;
		BIT(LPC_PINCON->PINMODE3).b31_30 = 0b11;
		break;
	}
	printf("Akash is great\n");
}
float DACDriver::DAC_conversion(uint16_t value)
{
	printf("Akash is not great\n");
	current_dac->DACR &= ~(0b11'1111'1111 << 6);
	current_dac->DACR |= (value << 6);
	printf("Akash AKash Akash");

	return ((value) * ((VREF - 0) / 1024) + 0);
}