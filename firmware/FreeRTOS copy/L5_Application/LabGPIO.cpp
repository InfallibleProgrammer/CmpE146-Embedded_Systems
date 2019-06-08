#include "LabGPIO.h"

LabGPIO::LabGPIO(uint8_t port, uint8_t pin)
{
	switch (port)
	{
	case 0: current = (LPC_GPIO_TypeDef*) LPC_GPIO0; printf("%p", current); break;
	case 1: current = (LPC_GPIO_TypeDef*) LPC_GPIO1; break;
	case 2: current = (LPC_GPIO_TypeDef*) LPC_GPIO2; break;
	case 3: current = (LPC_GPIO_TypeDef*) LPC_GPIO3; break;
	case 4: current = (LPC_GPIO_TypeDef*) LPC_GPIO4; break;
	}
	gpioPin = pin;
}

void LabGPIO::setAsInput()
{
	current->FIODIR &= ~(1 << gpioPin);
	current->FIODIR |= (0 << gpioPin);
}

void LabGPIO::setAsOutput()
{
	current->FIODIR &= ~(1 << gpioPin);
	current->FIODIR |= (1 << gpioPin);
}

void LabGPIO::setDirection(bool output)
{
	if (output == 1)
	{
		setAsOutput();
	}
	else
	{
		setAsInput();
	}
}

void LabGPIO::setHigh()
{
	current->FIOSET |= (1 << gpioPin);
}

void LabGPIO::setLow()
{
	current->FIOSET |= (0 << gpioPin);
}

void LabGPIO::set(bool high)
{
	if (high)
	{
		setHigh();
	}
	else
	{
		setLow();
	}
}

bool LabGPIO::getLevel()
{
	if (current->FIOPIN & (1 << gpioPin))
	{
		return true;
	}
	else
	{
		return false;
	}
}

