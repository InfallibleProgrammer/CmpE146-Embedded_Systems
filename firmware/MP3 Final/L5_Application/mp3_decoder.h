#ifndef MP3_DECODER_H_
#define MP3_DECODER_H_

#include "gpio.hpp"
#include "utilities.h"
#include <stdio.h>
#include "ssp0.h"
#include "FreeRTOS.h"
#include "semphr.h"

typedef union
{
    uint8_t byte;
    struct
    {
        uint8_t init_done: 1;
        uint8_t booted: 1;
        uint8_t use_interrupt: 1;
        uint8_t data_requested: 1;
    }__attribute__((packed));
} MP3_STATUS;

void d_req_int_handler();

class MP3_DECODER
{
public:
    enum MP3_OPCODES
    {
        SCI_READ = 0x03,
        SCI_WRITE = 0x02
    };

    enum SCI_REG
    {
        SCI_VOLUME      = 0x0B,
        SCI_MODE        = 0x00,
        SCI_AUDATA      = 0x05,
        SCI_CLKF        = 0x03,
        SCI_STATUS      = 0x01,
        SCI_HDAT0       = 0x08,
        SCI_HDAT1       = 0x09,
        SCI_WRAM        = 0x06,
        SCI_WRAMADDR    = 0x07,
        SCI_DECODETIME  = 0x04,
    };

    enum MP3_STATE
    {
        PLAY    = 0,
        PAUSE   = 1,
        STOP    = 2
    };

    MP3_DECODER();
    bool init(GPIO * RST, GPIO * DREQ, GPIO * CS, GPIO * XDCS);
    bool sendSDI(uint8_t info[], unsigned int size);
    uint16_t sendSCI(uint8_t opcode, uint8_t addr, uint16_t info);
    uint16_t sendSCI(uint8_t opcode, uint8_t addr, uint8_t *info, unsigned int size);
    void setVolume(uint8_t left, uint8_t right);
    void setBass(uint8_t value);
    void setTreble(uint8_t percentage);
    void sineTest(uint8_t frequency);
    SemaphoreHandle_t sending_cmd;
    MP3_STATUS status;
    MP3_STATE state;

private:
    //Pin with respect to device as slave
    GPIO * RST;     //DI:   Active Low Async Reset
    //GPIO * MISO;    //DO3:  Serial Output
                    //NOTE: If active, data is sampled in rising edge
    //GPIO * MOSI;    //DI:   Serial Input
    GPIO * DREQ;    //DO:   Data Request, Input Bus Ready
    //GPIO * SCLK;    //DI:   Clock for Serial Bus
    GPIO * XCS;     //DI:   Chip select (SCI)
    GPIO * XDCS;    //DI:   Data chip select (SDI)

    uint8_t sineTestStart[8] =  {0x53, 0xEF, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t sineTestEnd[8] =    {0x45, 0x78, 0x69, 0x74, 0x00, 0x00, 0x00, 0x00};
};



#endif /* MP3_DECODER_H_ */
