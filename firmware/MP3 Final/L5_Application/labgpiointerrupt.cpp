/*
 * labgpiointerrupt.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: Leophin
 */
#include "labgpiointerrupt.h"

LabGPIOInterrupts::LabGPIOInterrupts()
{
    memset(ISRfunction, 0, sizeof(ISRfunction));
}

void LabGPIOInterrupts::init()
{
    NVIC_EnableIRQ(EINT3_IRQn);
}

bool LabGPIOInterrupts::attachInterruptHandler(uint8_t port, uint32_t pin, void (*pin_isr)(void), InterruptCondition_E condition)
{
    //Check Pin
    if(pin < 0 || pin > 32) return false;

    //Check PORT
    switch(port)
    {
        case 0:
            //Set trigger condition
            switch(condition)
            {
                case rising_edge:
                    LPC_GPIOINT->IO0IntEnR |= (1 << pin);
                    LPC_GPIOINT->IO0IntEnF &= ~(1 << pin);
                    break;
                case falling_edge:
                    LPC_GPIOINT->IO0IntEnR &= ~(1 << pin);
                    LPC_GPIOINT->IO0IntEnF |= (1 << pin);
                    break;
                case both_edges:
                    LPC_GPIOINT->IO0IntEnR |= (1 << pin);
                    LPC_GPIOINT->IO0IntEnF |= (1 << pin);
                    break;
                default:
                    return false;
                    break;
            }
            break;
        case 2:
            //Set trigger condition
            switch(condition)
            {
                case rising_edge:
                    LPC_GPIOINT->IO2IntEnR |= (1 << pin);
                    LPC_GPIOINT->IO2IntEnF &= ~(1 << pin);
                    break;
                case falling_edge:
                    LPC_GPIOINT->IO2IntEnR &= ~(1 << pin);
                    LPC_GPIOINT->IO2IntEnF |= (1 << pin);
                    break;
                case both_edges:
                    LPC_GPIOINT->IO2IntEnR |= (1 << pin);
                    LPC_GPIOINT->IO2IntEnF |= (1 << pin);
                    break;
                default:
                    return false;
                    break;
            }
            break;
        default:
            return false;
            break;
    }
    LabGPIO PIN(pin, port);
    PIN.setAsInput();

    //Attach Interrupt to pin
    if(ISRfunction[port][pin] != NULL)
    {
        printf("Caution: Port %d Pin %d Interrupt was already set.\n", port, pin);
    }
    ISRfunction[port][pin] = pin_isr;
    return true;
}

void LabGPIOInterrupts::handle_interrupt()
{
    uint32_t int_flag = {0};
    if((LPC_GPIOINT->IO0IntStatR || LPC_GPIOINT->IO0IntStatF))
    {
        for(int i = 0; i < 32; i++)
        {
            int_flag = (LPC_GPIOINT->IO0IntStatR | LPC_GPIOINT->IO0IntStatF);
            if((1 << i) == int_flag)
            {
                LPC_GPIOINT->IO0IntClr = (1 << i);
                (*ISRfunction[0][i])();
//                printf("INT_PIN: %d\n", i);
            }
        }
    }
    else if((LPC_GPIOINT->IO2IntStatR || LPC_GPIOINT->IO2IntStatF))
    {
        int_flag = (LPC_GPIOINT->IO2IntStatR | LPC_GPIOINT->IO2IntStatF);
        for(int i = 0; i < 32; i++)
        {
            if((1 << i) == int_flag)
            {
                LPC_GPIOINT->IO2IntClr = (1 << i);
                (*ISRfunction[2][i])();
                printf("INT_PIN: %d\n", i);
            }
        }
    }
}
