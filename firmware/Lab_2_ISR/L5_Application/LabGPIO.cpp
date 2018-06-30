#include <LabGPIO.h>
#include <stdio.h>

LabGPIO::LabGPIO(uint8_t port_num, uint8_t y) { //x is pin, y is port
    switch (y) {
        case 0:
            LPC_GPIO = (LPC_GPIO_TypeDef*) LPC_GPIO0;
            break;
        case 1:
            port = (LPC_GPIO_TypeDef*) LPC_GPIO1;
            printf("%p", port); 
            break;
    case 2: port = (LPC_GPIO_TypeDef*) LPC_GPIO2; printf("%p", port); break;
    case 3: port = (LPC_GPIO_TypeDef*) LPC_GPIO3; printf("%p", port); break;
    case 4: port = (LPC_GPIO_TypeDef*) LPC_GPIO4; printf("%p", port); break;
    }
    printf("%p", port);
    pin = x;
}

LabGPIO::~LabGPIO() 
{
    setAsInput(); // default make it an input device as a safeguard in case someone attaches an input device without setting it up
}

void LabGPIO::setAsInput()
{
    LPC_GPIO->FIODIR &= ~(0 << pin);
}
void LabGPIO::setAsOutput()
{
    port->FIODIR |= (1 << pin);
}
void LabGPIO::setDirection(bool output) {
    if (output) 
    {
        setAsOutput();
    }
    else {
        setAsInput();
    }
}
void LabGPIO::setHigh() {
    port->FIOSET = (1 << pin);
}
void LabGPIO::setLow() {
    port->FIOCLR = (1 << pin);
}

void LabGPIO::set(bool high) {
    if (high) {
        setHigh();
    }
    else {
        setLow();
    }
}
bool LabGPIO::getLevel() {
    if (port->FIOPIN & (1 << pin)) {
        return true;
    }
    else {
        return false;
    }
}