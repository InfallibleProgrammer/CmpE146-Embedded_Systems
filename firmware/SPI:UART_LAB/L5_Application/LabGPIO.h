#ifndef LABGPIO_H
#define LABGPIO_H

#include <stdint.h>
#include "LPC17xx.h"


class LabGPIO
{
private:
    uint8_t pin;
    LPC_GPIO_TypeDef* port;
public:
    LabGPIO(uint8_t pin, uint8_t port);
    void setAsInput();
    void setAsOutput();
    void setDirection(bool output);
    void setHigh();
    void setLow();
    void set(bool high);
    bool getLevel();
    ~LabGPIO();
};

#endif