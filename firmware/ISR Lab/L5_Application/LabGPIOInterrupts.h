#ifndef LABGPIOINTERRUPTS_H
#define LABGPIOINTERRUPTS_H

#include <stdint.h>
#include "LPC17xx.h"
#include "lpc_isr.h"
#include "printf_lib.h"

typedef enum {
    rising_edge,
    falling_edge,
    both_edges,
} InterruptCondition_E;

class LabGPIOInterrupts
{
private:
    static LabGPIOInterrupts* instance;
    void (*gpio_isr[2][30])(void);
    uint8_t pin;
    uint8_t portState;
    LPC_GPIO_TypeDef* port;
    bool port0;

public:
    static LabGPIOInterrupts* getInstance();

    /**
     * This should configure NVIC to notice EINT3 IRQs; use NVIC_EnableIRQ()
     */
    void init();

    /**
     * This handler should place a function pointer within the lookup table for the handle_interrupt() to find.
     *
     * @param[in] port         specify the GPIO port
     * @param[in] pin          specify the GPIO pin to assign an ISR to
     * @param[in] pin_isr      function to run when the interrupt event occurs
     * @param[in] condition    condition for the interrupt to occur on. RISING, FALLING or BOTH edges.
     * @return should return true if valid ports, pins, isrs were supplied and pin isr insertion was sucessful
     */
    bool attachInterruptHandler(uint8_t po, uint8_t pi, void (*pin_isr)(void), InterruptCondition_E condition);

    /**
     * This function is invoked by the CPU (through c_eint3_handler) asynchronously when a Port/Pin
     * interrupt occurs. This function is where you will check the Port status, such as IO0IntStatF,
     * and then invoke the user's registered callback and find the entry in your lookup table.
     *
     * VERY IMPORTANT!
     *  - Be sure to clear the interrupt flag that caused this interrupt, or this function will be called
     *    repetitively and lock your system.
     *  - NOTE that your code needs to be able to handle two GPIO interrupts occurring at the same time.
     */
    void handle_interrupt(void);
    void setRisingEdge(bool port_0);
    void setFallingEdge(bool port_0);

    // Optional destructor
    //~LabGPIOInterrupts();
};

#endif
