/*
 *     SocialLedge.com - Copyright (C) 2013
 *
 *     This file is part of free software framework for embedded processors.
 *     You can use it and/or distribute it as long as this copyright header
 *     remains unmodified.  The code is free for personal use and requires
 *     permission to use in a commercial product.
 *
 *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *     You can reach the author of this software at :
 *          p r e e t . w i k i @ g m a i l . c o m
 */

/**
 * @file
 * @brief This is the application entry point.
 */

#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "gpio.hpp"
#include "LabSPI.h"
#include "printf_lib.h"
#include "ssp0.h"

void writeSCI(uint8_t reg_addr, uint16_t value);
void setVolume(uint8_t left, uint8_t right);
uint16_t readSCI(uint16_t reg_addr);
uint16_t getDecodeTime();
// bool init();


GPIO CS(P0_0);
GPIO XDCS(P0_1); // pin, port layout
GPIO datareq(P2_6);
GPIO RST(P0_30);

int main(void)
{
    ssp0_init(8);
    // delay_ms(5000);
    // while (1 == 1) {
    //     ssp0_exchange_byte(0x02);

    // }
    delay_ms(1000);
    CS.setAsOutput();
    XDCS.setAsOutput();
    RST.setAsOutput();
    datareq.setAsInput();
    RST.setLow();
    delay_ms(5);
    RST.setHigh();
    delay_ms(5);
    XDCS.setHigh();

    CS.setHigh();
    delay_ms(5);
    delay_ms(5);
    printf("second delay occured before start of program\n");

    u0_dbg_printf("Do first data transfer. -tests 158\n");
    writeSCI(0x0, ((1 << 5) | 0x0810));

    writeSCI(0x0003, 0x6000);
    writeSCI(0x0005, 0xAC45);
    setVolume(70, 70);
    u0_dbg_printf("Do final data transfer\n");
    CS.setLow();
    ssp0_exchange_byte(0x2);
    ssp0_exchange_byte(0x0);
    ssp0_exchange_byte(0x08);
    ssp0_exchange_byte(0x24);
    CS.setHigh();

    delay_ms(5);

    while (!datareq.read());

    delay_ms(5);

    XDCS.setLow();
    ssp0_exchange_byte(0x53);
    ssp0_exchange_byte(0xef);
    ssp0_exchange_byte(0x6e);
    ssp0_exchange_byte(0x30);
    ssp0_exchange_byte(0x00);
    ssp0_exchange_byte(0x00);
    ssp0_exchange_byte(0x00);
    ssp0_exchange_byte(0x00);
    XDCS.setHigh();

    delay_ms(10000);

    XDCS.setLow();
    ssp0_exchange_byte(0x45);
    ssp0_exchange_byte(0x78);
    ssp0_exchange_byte(0x69);
    ssp0_exchange_byte(0x74);
    ssp0_exchange_byte(0x00);
    ssp0_exchange_byte(0x00);
    ssp0_exchange_byte(0x00);
    ssp0_exchange_byte(0x00);
    XDCS.setHigh();

}

void writeSCI(uint8_t reg_addr, uint16_t value)
{
    u0_dbg_printf("WriteSCI: I made it into the function %x %x\n", reg_addr, value);
    while (!datareq.read()) {
        delay_ms(50);
    }
    CS.setLow();
    ssp0_exchange_byte(0x2); // write
    ssp0_exchange_byte(reg_addr); // mode reg
    ssp0_exchange_byte(value >> 8);
    ssp0_exchange_byte(value & 0xff);
    CS.setHigh();
    u0_dbg_printf("WriteSCI: i have made it past the hard part\n");
}
void setVolume(uint8_t left, uint8_t right)
{
    u0_dbg_printf("Turn the volume up boiii\n");
    uint16_t v;
    v = left;
    v <<= 8;
    v |= right;
    u0_dbg_printf("about to use WriteSCI function");
    writeSCI(0x000B, v);
}

uint16_t readSCI(uint16_t reg_addr)
{
    while (datareq.read() != 1) {
        delay_ms(50);
    }
    uint16_t data;
    CS.setLow();
    ssp0_exchange_byte(0x3); // read
    ssp0_exchange_byte(reg_addr); //reg

    data = ssp0_exchange_byte(reg_addr >> 8);
    data <<= 8;
    data |= ssp0_exchange_byte(reg_addr & 0xff);
    CS.setHigh();
    return data;
}


uint16_t getDecodeTime()
{
    return readSCI(0xC028);
}

// bool init()
// {
//     RST.setAsOutput();
//     RST.setHigh();
//     datareq.setAsInput();

//     delay_ms(5);

//     XDCS.setAsOutput();
//     XDCS.setHigh();

//     CS.setAsOutput();
//     CS.setHigh();

//     delay_ms(5);

//     writeSCI(0x00, ((1 << 5) | 0x0810));
//     writeSCI(0x03, 0x6000);
//     writeSCI(0x05, 0xAC45);
//     setVolume(70, 70);

//     return true;
// }