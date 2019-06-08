#ifndef LABGPIOINTERRUPTS_H
#define LABGPIOINTERRUPTS_H

#include <stdint.h>
#include "LPC17xx.h"
#include "lpc_isr.h"
#include "printf_lib.h"
typedef void (*void_func_t) (void);
typedef enum {
    rising_edge,
    falling_edge,
    both_edges,
} InterruptCondition_E;

class LabGPIOInterrupts
{
private:
    static LabGPIOInterrupts* instance;
    void_func_t gpio_isr[2][30];
    uint8_t pin;
    uint8_t portState;
    LPC_GPIO_TypeDef* port;
    bool port0;

public:
    static LabGPIOInterrupts* getInstance();
    void init();
    bool attachInterruptHandler(uint8_t po, uint8_t pi, void (*pin_isr)(void), InterruptCondition_E condition);
    void handle_interrupt(void);
    void setRisingEdge(bool port_0);
    void setFallingEdge(bool port_0);

    // Optional destructor
    //~LabGPIOInterrupts();
};

#endif