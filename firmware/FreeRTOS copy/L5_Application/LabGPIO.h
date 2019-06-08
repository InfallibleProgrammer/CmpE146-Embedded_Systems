#ifndef LABGPIO_H
#define LABGPIO_H

#include <stdio.h>
#include "LPC17xx.h"

class LabGPIO

//memory bus take 16bits,
//int is always 32 bits. 
//uint4_t, uint8_t, uint16_t, uint32_t, uint64_t 

{
private:
    LPC_GPIO_TypeDef* current; 
    uint8_t gpioPin;
public:
    /**
     * You should not modify any hardware registers at this point
     * You should store the port and pin using the constructor.
     *
     * @param {uint8_t} pin  - pin number between 0 and 32
     */
	LabGPIO(uint8_t port, uint8_t pin);
    /**
     * Should alter the hardware registers to set the pin as an input
     */
	void setAsInput();
    /**
     * Should alter the hardware registers to set the pin as an input
     */
	void setAsOutput();
    /**
     * Should alter the set the direction output or input depending on the input.
     *
     * @param {bool} output - true => output, false => set pin to input
     */
    void setDirection(bool output);
    /**
     * Should alter the hardware registers to set the pin as high
     */
    void setHigh();
    /**
     * Should alter the hardware registers to set the pin as low
     */
    void setLow();
    /**
     * Should alter the hardware registers to set the pin as low
     *
     * @param {bool} high - true => pin high, false => pin low
     */
    void set(bool high);
    /**
     * Should return the state of the pin (input or output, doesn't matter)
     *
     * @return {bool} level of pin high => true, low => false
     */
	bool getLevel();
	~LabGPIO();
};

#endif