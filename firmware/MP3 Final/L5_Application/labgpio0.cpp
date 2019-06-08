/*
 * gpio.cpp
 *
 *  Created on: Jun 11, 2018
 *      Author: Leophin
 */
#include "labgpio0.h"

LabGPIO::LabGPIO(uint8_t pin, uint8_t port)
{
    PIN = pin;
    PORT = port;
    switch(PORT)
    {
        case 0:
            LPC_GPIO0->FIODIR &= ~(1 << PIN);
            LPC_GPIO0->FIODIR |= (1 << PIN);
            break;
        case 1:
            LPC_GPIO1->FIODIR &= ~(1 << PIN);
            LPC_GPIO1->FIODIR |= (1 << PIN);
            break;
        case 2:
            LPC_GPIO2->FIODIR &= ~(1 << PIN);
            LPC_GPIO2->FIODIR |= (1 << PIN);
            break;
        default:
            break;
    }
}

void LabGPIO::setAsInput()
{
    switch(PORT)
    {
        case 0:
            LPC_GPIO0->FIODIR &= ~(1 << PIN);
            break;
        case 1:
            LPC_GPIO1->FIODIR &= ~(1 << PIN);
            break;
        case 2:
            LPC_GPIO2->FIODIR &= ~(1 << PIN);
            break;
        default:
            break;
    }
}

void LabGPIO::setAsOutput()
{
    switch(PORT)
    {
        case 0:
            LPC_GPIO0->FIODIR |= (1 << PIN);
            break;
        case 1:
            LPC_GPIO1->FIODIR |= (1 << PIN);
            break;
        case 2:
            LPC_GPIO2->FIODIR |= (1 << PIN);
            break;
        default:
            break;
    }
}

void LabGPIO::setDirection(bool output)
{
    if(output)
    {
        switch(PORT)
        {
            case 0:
                LPC_GPIO0->FIODIR |= (1 << PIN);
                break;
            case 1:
                LPC_GPIO1->FIODIR |= (1 << PIN);
                break;
            case 2:
                LPC_GPIO2->FIODIR |= (1 << PIN);
                break;
            default:
                break;
        }
    }
    else
    {
        switch(PORT)
        {
            case 0:
                LPC_GPIO0->FIODIR &= ~(1 << PIN);
                break;
            case 1:
                LPC_GPIO1->FIODIR &= ~(1 << PIN);
                break;
            case 2:
                LPC_GPIO2->FIODIR &= ~(1 << PIN);
                break;
            default:
                break;
        }
    }
}

void LabGPIO::setHigh()
{
    switch(PORT)
    {
        case 0:
            LPC_GPIO0->FIOPIN |= (1 << PIN);
            break;
        case 1:
            LPC_GPIO1->FIOPIN |= (1 << PIN);
            break;
        case 2:
            LPC_GPIO2->FIOPIN |= (1 << PIN);
            break;
        default:
            break;
    }
}

void LabGPIO::setLow()
{
    switch(PORT)
    {
        case 0:
            LPC_GPIO0->FIOPIN &= ~(1 << PIN);
            break;
        case 1:
            LPC_GPIO1->FIOPIN &= ~(1 << PIN);
            break;
        case 2:
            LPC_GPIO2->FIOPIN &= ~(1 << PIN);
            break;
        default:
            break;
    }
}

void LabGPIO::set(bool high)
{
    if(high)
    {
        switch(PORT)
        {
            case 0:
                LPC_GPIO0->FIOPIN |= (1 << PIN);
                break;
            case 1:
                LPC_GPIO1->FIOPIN |= (1 << PIN);
                break;
            case 2:
                LPC_GPIO2->FIOPIN |= (1 << PIN);
                break;
            default:
                break;
        }
    }
    else
    {
        switch(PORT)
        {
            case 0:
                LPC_GPIO0->FIOPIN &= ~(1 << PIN);
                break;
            case 1:
                LPC_GPIO1->FIOPIN &= ~(1 << PIN);
                break;
            case 2:
                LPC_GPIO2->FIOPIN &= ~(1 << PIN);
                break;
            default:
                break;
        }
    }
}

bool LabGPIO::getLevel()
{
    switch(PORT)
    {
        case 0:
            return (LPC_GPIO0->FIOPIN & (1 << PIN));
            break;
        case 1:
            return (LPC_GPIO1->FIOPIN & (1 << PIN));
            break;
        case 2:
            return (LPC_GPIO2->FIOPIN & (1 << PIN));
            break;
        default:
            return false;
            break;
    }
}
