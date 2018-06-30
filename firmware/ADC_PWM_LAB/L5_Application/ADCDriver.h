#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdio.h>
#include "LPC17xx.h"
#include "stdint.h"


class ADCDriver
{
public:
    enum ADC_PIN
    {
        ADC_PIN_0_25,       // AD0.2 <-- Light Sensor -->
        ADC_PIN_0_26,       // AD0.3
        ADC_PIN_1_30,       // AD0.4
        ADC_PIN_1_31,       // AD0.5
    };

    // Nothing needs to be done within the default constructor
    ADCDriver(void);
    void adcInitBurstMode(void);
    void adcSelectPin(ADC_PIN adc_pin_arg);
    float readADCVoltageByChannel(uint8_t adc_channel_arg);
private:
};

#endif