#include "LabSPI.h"
LPC_SSP_TypeDef * SSP[] = {LPC_SSP0, LPC_SSP1};

LabSPI::LabSPI()
{

}

LabSPI::~LabSPI()
{

}

bool LabSPI::init(Peripheral peripheral, uint8_t data_size_select, FrameModes format, uint8_t divide)
{

    if (peripheral == SSP0)
    {
        current_SPP = (LPC_SSP_TypeDef*) LPC_SSP0;
        LPC_SC->PCONP |= (1 << 21); // power on the device
        BIT(LPC_SC->PCLKSEL1).b11_10 = 0b01; //reset bits 11, 10 then set them to 01. Sets the periclock to
        BIT(LPC_PINCON->PINSEL0).b31_30 = 0b10; //reset bits 31, 30 and set to 1,0.
        LPC_PINCON->PINSEL1 &= ~(0b111111);
        LPC_PINCON->PINSEL1 |= (0b10101000 << 0); //sets MISO, MOSI, and GPIO(used for select)
        current_SPP->CR0 &= ~(0XF);
        current_SPP->CR0 |= (data_size_select - 1); //sets the data
        BIT(current_SPP->CR0).b5_4 = format; //resets format bits, and sets them to correct format

        current_SPP->CR1 |= (1 << 1); //SSP enable

        current_SPP->CPSR &= ~(0xF);
        current_SPP->CPSR |= divide;
        return true;
    }
    else if (peripheral == SSP1)
    {
        current_SPP = (LPC_SSP_TypeDef*) LPC_SSP1;
        LPC_SC->PCONP |= (1 << 10);
        BIT(LPC_SC->PCLKSEL0).b21_20 = 0b11;

        LPC_PINCON->PINSEL0 &= ~(0xFF << 12);
        LPC_PINCON->PINSEL0 |= (0b10101000 << 12); //set miso1, mosi1, and GPIO for select

        current_SPP->CR0 &= ~(0XFF);
        current_SPP->CR0 |= (data_size_select - 1); //sets how big the data is. 8 bits, 16 bits, etc

        current_SPP->CR0 &= ~(0b11 << 4); //resets frame type
        current_SPP->CR0 |= (format << 4); //sets the frame type

        current_SPP->CR1 |= (1 << 1); //SSP enable

        current_SPP->CPSR &= ~(0xF); //clock divisor 
        current_SPP->CPSR |= divide; 

        return true;
    }
    else
    {
        return false;
    }

}

uint8_t LabSPI::transfer(uint8_t send)
{
    current_SPP->DR = send;
    while ((current_SPP->SR & (1 << 4))); //while the status register is busy, stay here
    return current_SPP->DR; //Return data. 32 bit register, only first 16 bits are datat
}
