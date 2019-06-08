#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "stdio.h"
#include "io.hpp"


/******For proper operation of the SJOne board, do NOT configure any pins as ADC except for 0.26, 1.31, 1.30****/
class ADCDriver
{
public:
    enum ADC_PIN
    {
        ADC_PIN_0_25,       // AD0.2 <-- Light Sensor -->
        ADC_PIN_0_26,       // AD0.3
        ADC_PIN_1_30,       // AD0.4
        ADC_PIN_1_31,       // AD0.5
      
    //      These ADC channels are compromised on the SJ-One, hence you do not need to support them
    //     ADC_PIN_0_23 = 0,   // AD0.0
    //     ADC_PIN_0_24,       // AD0.1
    //     ADC_PIN_0_3,        // AD0.6
    //     ADC_PIN_0_2         // AD0.7
        
    };

    /**
    * Nothing needs to be done within the default constructor
    */
    ADCDriver();
    
    /**
    * 1) Powers up ADC peripheral
    * 2) Set peripheral clock
    * 2) Enable ADC
    * 3) Select ADC channels
    * 4) Enable burst mode
    *
    * @param channels_to_enable (optional param) bit mask to enable up to 8 ADC channels
    */
    void adcInitBurstMode();//uint8_t channels_to_enable = 0xFF);

    /**
    * 1) Selects ADC functionality of any of the 8 pins that are ADC capable
    * 
    * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
    *
    * WARNING: For proper operation of the SJOne board, do NOT configure any pins
    *           as ADC except for 0.26, 1.31, 1.30
    */
    void adcSelectPin(ADC_PIN adc_pin_arg);
    
    /**
    * 1) Returns the value of the 12bit register reading of a given ADC pin
    *
    * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
    */
    // uint16_t readADCRawByPin(ADC_PIN adc_pin_arg);
    
    // /**
    // * 1) Returns the value of the 12bit register reading of a given ADC channel
    // *
    // * @param adc_channel_arg is the number (0 through 7) of the desired ADC channel.
    // */
    // uint16_t readADCRawByChannel(uint8_t adc_channel_arg);
    
    // /*
    // * 1) Returns the voltage reading of a given ADC pin
    // *
    // * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
    // */
    // float readADCVoltageByPin(ADC_PIN adc_pin_arg);
    
    /**
    * 1) Returns the voltage reading of a given ADC channel
    *
    * @param adc_channel_arg is the number (0 through 7) of the desired ADC channel.
    */
    float readADCVoltageByChannel(uint8_t adc_channel_arg);
};

#endif