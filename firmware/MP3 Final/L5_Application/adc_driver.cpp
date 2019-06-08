#include "adc_driver.h"
#include "LPC17xx.h"


//	do nothing
ADCDriver::ADCDriver()
{

}
    
    /**
    * 1) Powers up ADC peripheral
    * 2) Set peripheral clock
    * 2) Enable ADC
    * 3) Select ADC channels
    * 4) Enable burst mode
    *
    * @param channels_to_enable (optional param) bit mask to enable up to 8 ADC channels
    */
void ADCDriver::adcInitBurstMode()//uint8_t channels_to_enable)
{
    LPC_SC->PCONP |= (0x1 << 12);     //0) Powers up ADC (PCADC, bit 12 of PCONP)
    LPC_SC->PCLKSEL0 &= ~(1 << 22); //this should be 48Mhz by default, don't alter
    LPC_ADC->ADCR |= (0x07 << 8);      //1) Set peripheral clock, CLKDIV/(1+9)
    LPC_ADC->ADCR |= (0x1 << 21);     //2) Enable ADC
    LPC_ADC->ADCR &= ~(0xFF << 0);      //3) clear all channels
    LPC_ADC->ADCR |= (0x7 << 3);      //3) Select ADC channels AD03, AD04, AD05
    LPC_ADC->ADCR |= (0x1 << 16);     //4) Enable burst mode
}

    /**
    * 1) Selects ADC functionality of any of the 8 pins that are ADC capable
    * 
    * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
    *
    * WARNING: For proper operation of the SJOne board, do NOT configure any pins
    *           as ADC except for 0.26, 1.31, 1.30
    */
void ADCDriver::adcSelectPin(ADC_PIN adc_pin_arg)
{
    switch(adc_pin_arg)
    {
        // case ADC_PIN_0_25:   //ignore p0.25 per instructions
        //     break;
        case ADC_PIN_0_26:      //set up AD03
                LPC_PINCON->PINSEL1 |= (0x1 << 20); //p0.26 is now adc enabled
                LPC_PINCON->PINMODE1 |= (0x3 << 20);//0x2 = no PxR, 0x3=PDR
            break;
        case ADC_PIN_1_30:      //set up AD04
                LPC_PINCON->PINSEL3 |= (0x3 << 28); //p1.30 is now adc enabled
                LPC_PINCON->PINMODE3 |= (0x3 << 28);
            break;
        case ADC_PIN_1_31:      //set up AD05
                LPC_PINCON->PINSEL3 |= (0x3 << 30); //p1.30 is now adc enabled
                LPC_PINCON->PINMODE3 |= (0x3 << 30);
            break;
        default:
            break;
    }
}
    
//     /**
//     * 1) Returns the value of the 12bit register reading of a given ADC pin
//     *
//     * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
//     */
// uint16_t ADCDriver::readADCRawByPin(ADC_PIN adc_pin_arg)
// {

// }
    
//     /**
//     * 1) Returns the value of the 12bit register reading of a given ADC channel
//     *
//     * @param adc_channel_arg is the number (0 through 7) of the desired ADC channel.
//     */
// uint16_t ADCDriver::readADCRawByChannel(uint8_t adc_channel_arg)
// {

// }
    
//     /**
//     * 1) Returns the voltage reading of a given ADC pin
//     *
//     * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
//     */
// float ADCDriver::readADCVoltageByPin(ADC_PIN adc_pin_arg)
// {

// }
    
    /**
    * 1) Returns the voltage reading of a given ADC channel
    *
    * @param adc_channel_arg is the number (0 through 7) of the desired ADC channel.
    */
float ADCDriver::readADCVoltageByChannel(uint8_t adc_channel_arg)
{
    float adc_value = 0;

    switch(adc_channel_arg)
    {
        // case ADC_PIN_0_25:       //ignore this pin
        //     adc_value = LPC_ADC->ADDR2;
        //     break;
        case 3: //ADC channel 3
            // adc_value = (LPC_ADC->ADDR3 >> 4);// & (0xFF << 4));
            adc_value = (LPC_ADC->ADDR3 & (0xFFF << 4)) >> 4;
            // printf("16-bits: %lx\n", adc_value);
            break;
        case 4: //ADC channel 4
            adc_value = (LPC_ADC->ADDR4 & (0xFFF << 4)) >> 4;
            break;
        case 5: //ADC channel 5
            adc_value = (LPC_ADC->ADDR5 & (0xFFF << 4)) >> 4;
            break;
        default: 
            adc_value = 0;
            break;
    }
    return adc_value;
}


