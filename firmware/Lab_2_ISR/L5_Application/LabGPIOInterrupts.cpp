#include "LabGPIOInterrupts.h"
#include "utilities.h"
#include "io.hpp"
#include <stdio.h>

LabGPIOInterrupts* LabGPIOInterrupts::instance = 0;

LabGPIOInterrupts* LabGPIOInterrupts::getInstance() {
	if (instance == 0) {
		instance = new LabGPIOInterrupts();
	}
	return instance;
}

void LabGPIOInterrupts::init() {
	NVIC_EnableIRQ(EINT3_IRQn);
}

bool LabGPIOInterrupts::attachInterruptHandler(uint8_t po, uint8_t pi, void (*pin_isr)(void), InterruptCondition_E condition) {
	
	LPC_GPIO_TypeDef* LPC_GPIO;
	switch (po) {
	case 0: LPC_GPIO = (LPC_GPIO_TypeDef*) LPC_GPIO0; portState = 0; port0 = 1; break;
	case 2: port = (LPC_GPIO_TypeDef*) LPC_GPIO2; portState = 2; port0 = 0; break;
	default: return false;
	}
	pin = pi;
	port->FIODIR &= !(1 << pin);
	if (rising_edge == condition) {
		setRisingEdge(port0);
	}
	else if (falling_edge == condition) {
		setFallingEdge(port0);
		clearRisingEdgeTrigger(port)
	}
	else if (both_edges == condition) {
		setFallingEdge(port0);
		setRisingEdge(port0);
	}

	gpio_isr[portState][pin] = pin_isr;
	return true;
}
void LabGPIOInterrupts::handle_interrupt(void) {

	if(port0)
	if (port0) {
		if (((LPC_GPIOINT->IO0IntStatR & (1 << pin)) || (LPC_GPIOINT->IO0IntStatF & (1 << pin))) == 1) {
			gpio_isr[portState][pin]();
			LPC_GPIOINT->IO0IntClr |= (1 << pin);
			printf("%d", LPC_GPIOINT->IO0IntStatR & (1 << pin));
		}
		else {
		}
	}
	else {
		if (((LPC_GPIOINT->IO2IntStatR & (1 << pin)) || (LPC_GPIOINT->IO2IntStatF & (1 << pin))) == 1) {
			gpio_isr[portState][pin]();
			LPC_GPIOINT->IO2IntClr |= (1 << pin);
		}
		else {

		}
	}
}

void LabGPIOInterrupts::setRisingEdge(bool port_0) {
	if (port_0) {
		LPC_GPIOINT->IO0IntEnR |= (1 << pin);
	}
	else {
		LPC_GPIOINT->IO2IntEnR |= (1 << pin);
	}
}

void LabGPIOInterrupts::setFallingEdge(bool port_0) {
	if (port_0) {
		LPC_GPIOINT->IO0IntEnF |= (1 << pin);
	}
	else {
		LPC_GPIOINT->IO2IntEnF |= (1 << pin);
	}
}

