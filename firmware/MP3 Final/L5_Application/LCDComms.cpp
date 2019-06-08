#include "LCDComms.h"
#include <string.h>

Uart3 &lcdComms = Uart3::getInstance();

LCDCOMMS::LCDCOMMS()
{
}
LCDCOMMS::~LCDCOMMS()
{
}
void LCDCOMMS::initLCD(uint8_t txRate, uint8_t receiveQueue, uint8_t transferQueue)
{
    lcdComms.init(txRate, receiveQueue, transferQueue);
    delay_ms(1000);

}
void LCDCOMMS::CLR()
{
    lcdComms.printf("$CLR_SCR\n");
}
void LCDCOMMS::setBright(uint8_t percentage)
{
    lcdComms.printf("$BLIGHT:%i\n", percentage);
}

void LCDCOMMS::CLRLine(uint8_t row)
{
    if (row < 5 && row >= 0) {
        lcdComms.printf("CLR_LINE:%i\n", row);
    }
    else
    {
        CLR();
    }
}

void LCDCOMMS::write(uint8_t column, uint8_t row, char *string)
{
    lcdComms.printf("$GOTO:%i:%i\n", column, row);
    lcdComms.printf("%s", string);
}

void LCDCOMMS::setL(uint8_t row, char *string)
{
    lcdComms.printf("$L:0:%s\n", string);
}
