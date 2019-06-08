#ifndef LABUART_H
#define LABUART_H

#include <stdint.h>
#include "LPC17xx.h"
#include "lpc_isr.h"

class LabUART
{
private:
    LPC_UART_TypeDef* current_uart;
public:
    enum Peripheral
    {
        DNU0, //DO NOT USE
        DNU1, //DO NOT USE
        UART2,
        UART3,
    };
    LabUART();
    ~LabUART();
    void init(Peripheral peripheral, uint8_t data_size_select, uint32_t baud, void (*uart_isr)(void));
    void tx(uint8_t data);
    uint8_t rx();


    // TODO: Fill in methods for init(), transmit(), receive() etc.

    // Optional: For the adventurous types, you may inherit from "CharDev" class to get a lot of funcionality for free
};

#endif
