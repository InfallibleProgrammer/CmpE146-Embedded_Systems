#include "ADCDriver.h"

const float VREF = 3.3; //Reference voltage
const uint16_t MaxPercent = 4096; // 100% value which is 2^12
const int8_t ADCPwr = 21;
const int8_t ADCBit = 12;
const int8_t ADCDiv = 8;
const int8_t ADCBurst = 16;
const int8_t myStartBit = 24;
const uint8_t myDoneBit = 31;


ADCDriver::ADCDriver()
{

}

void ADCDriver::adcInitBurstMode()
{
	LPC_SC->PCONP |= (1 << ADCBit);
	LPC_ADC->ADCR = 0; //Set the whole register to C instead of
	//clearing bits everytime.
	LPC_ADC->ADCR |= (1 << 21);
	LPC_SC->PCLKSEL0  &= ~(3 << 24); // used to be 3 by 24
	LPC_SC->PCLKSEL0 |= (1 << 24);
	LPC_ADC->ADCR |= (0b11 << 8); //set clkdiv to 7
	LPC_ADC->ADCR |= (0b1111111 << 0);
	LPC_ADC->ADCR |= (1 << ADCBurst);
	LPC_ADC->ADCR &= ~(0b000 < myStartBit);
}

void ADCDriver::adcSelectPin(ADC_PIN adc_pin_arg)
{
	switch (adc_pin_arg)
	{
	case (ADC_PIN_0_25):
		LPC_PINCON->PINSEL1 &= ~(0b11 << 18);
		LPC_PINCON->PINMODE1 &= ~(0b11 << 18);
		LPC_PINCON->PINSEL1 |= (0b01 << 18);
		LPC_PINCON->PINMODE1 |= (0b11 << 18);
		break;
	case (ADC_PIN_0_26):
		LPC_PINCON->PINSEL1 &= ~(0b11 << 20);
		LPC_PINCON->PINMODE1 &= ~(0b11 << 20);
		LPC_PINCON->PINMODE1 |= (0b11 << 28);
		LPC_PINCON->PINSEL1 |= (0b01 << 20);
		break;
	case (ADC_PIN_1_30):
		LPC_PINCON->PINSEL3 &= ~(0b11 << 28);
		LPC_PINCON->PINMODE3 &= ~(0b11 << 28);
		LPC_PINCON->PINMODE3 |= (0b11 << 28);
		LPC_PINCON->PINSEL3 |= (0b11 << 28);
		break;
	case (ADC_PIN_1_31):
		LPC_PINCON->PINSEL3 &= ~(0b11 << 30);
		LPC_PINCON->PINMODE3 &= ~(0b11 << 30);
		LPC_PINCON->PINMODE3 |= (0b11 << 30);
		LPC_PINCON->PINSEL3 |= (0b11 << 30);
		break;
	}
}


float ADCDriver::readADCVoltageByChannel(uint8_t adc_channel_arg)
{
	volatile uint32_t* adc_Raw_Voltage_Reg; //address to adc percentage(raw value)

	switch (adc_channel_arg)
	{
	case 2:
		adc_Raw_Voltage_Reg = &LPC_ADC->ADDR2;
		break;
	case 3:
		adc_Raw_Voltage_Reg = &LPC_ADC->ADDR3;
		break;
	case 4:
		adc_Raw_Voltage_Reg = &LPC_ADC->ADDR4;
		break;
	case 5:
		adc_Raw_Voltage_Reg = &LPC_ADC->ADDR5;
		break;
	default:
		return 0;
	}

	while ((*adc_Raw_Voltage_Reg & (1 << 31)) == 0); //wait bit 31 is 1. Bit 32 is the done bit
	//stating that the adc_voltage value is loaded.

	float voltage = ((((*adc_Raw_Voltage_Reg >> 4) & 0xFFF) * VREF) / MaxPercent);

	return voltage;
}