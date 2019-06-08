#include "LabUART.h"


const uint32_t PCLK = 48000000; // MCU set peripheral clock

void LabUART::init(Peripheral peripheral, uint8_t data_size_select, uint32_t baud, void (*uart_isr)(void))
{
    uint16_t temp;
    uint8_t DLM_bits;
    uint8_t DLL_bits;

    if (peripheral == 2)
    {
        current_uart = (LPC_UART_TypeDef*) LPC_UART2;
        LPC_SC->PCONP |= (1 << 24); //power on UART 2
        BIT(LPC_SC->PCLKSEL1).b17_16 = 0b01; //Set periclock divide by 1

        BIT(current_uart->LCR).b1_0 = (data_size_select - 5); //5 bit = 00, 6bit = 01, 7bit = 10, 8bit = 11
        temp = (PCLK / (16 * baud));
        DLM_bits = temp / 256;
        DLL_bits = temp % 256;

        BIT(current_uart->LCR).b7 = 0b1; //enable buad rate to modified using line control reg
        current_uart->DLM = DLM_bits; //set DLM bits
        current_uart->DLL = DLL_bits; //set DLL bits
        BIT(current_uart->LCR).b7 = 0b0; //disable baud rate modification bit

        //BIT(current_uart->FCR).b0 = 0b1; //FIFO Enable bit
        BIT(LPC_PINCON->PINSEL4).b17_16 = 0b10; //set pim 2.8 to TX mode
        BIT(LPC_PINCON->PINSEL4).b19_18 = 0b10; //set pim 2.9 to RX mode

        BIT(current_uart->IER).b0 = 0b1; //enables interrupts
        NVIC_EnableIRQ(UART2_IRQn);
        isr_register(UART2_IRQn, uart_isr);
    }
    else if (peripheral == 3)
    {
        current_uart = (LPC_UART_TypeDef*) LPC_UART3;
        BIT(LPC_SC->PCONP).b25 = 0b1;
        BIT(LPC_SC->PCLKSEL1).b19_18 = 0b01;
        BIT(current_uart->LCR).b1_0 = (data_size_select - 5);
        temp = (PCLK / (16 * baud));
        DLM_bits = temp / 256;
        DLL_bits = temp % 256;
        BIT(current_uart->LCR).b7 = 0b1;
        current_uart->DLM = DLM_bits; //set DLM bits
        current_uart->DLL = DLL_bits; //set DLL bits
        BIT(current_uart->LCR).b7 = 0b0;
        //BIT(current_uart->FCR).b0 = 0b1;
        BIT(LPC_PINCON->PINSEL9).b25_24 = 0b11;
        BIT(LPC_PINCON->PINSEL9).b27_26 = 0b11;
        NVIC_EnableIRQ(UART3_IRQn);
        isr_register(UART3_IRQn, uart_isr);
    }
    else
    {

    }
}

void LabUART::tx(uint8_t data)
{
    current_uart->THR = data;
    while((current_uart->LSR & (1 << 6)) == 0); //data is being trasmitted. 1 means its empty
}

uint8_t LabUART::rx()
{
    uint8_t in_data = current_uart->RBR;
    return in_data;
}


LabUART::LabUART()
{

}

LabUART::~LabUART()
{

}
