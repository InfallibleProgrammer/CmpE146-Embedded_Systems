#ifndef LCDCOMMS_H
#define LCDCOMMS_H

#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "uart3.hpp"
#include <stdint.h>

class LCDCOMMS {
public:
    LCDCOMMS();
    ~LCDCOMMS();
    void initLCD(uint8_t txRate, uint8_t receiveQueue, uint8_t transferQueue);
    void CLR();
    void setBright(uint8_t percent);
    void CLRLine(uint8_t row);
    void write(uint8_t column, uint8_t row, char *string);
    void setL(uint8_t row, char *string);
private:
};


#endif
