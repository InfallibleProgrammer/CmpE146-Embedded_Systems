#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include <stdio.h>
#include "LPC17xx.h"
#include "stdint.h"

class PWMDriver
{
public:
    enum PWM_PIN
    {
        PWM_PIN_2_0,    // PWM1.1
        PWM_PIN_2_1,    // PWM1.2
        PWM_PIN_2_2,    // PWM1.3
        PWM_PIN_2_3,    // PWM1.4
        PWM_PIN_2_4,    // PWM1.5
        PWM_PIN_2_5,    // PWM1.6
    };

    /// Nothing needs to be done within the default constructor
    PWMDriver(void);
    void pwmSelectAllPins(void);
    void pwmSelectPin(PWM_PIN pwm_pin_arg);
    void pwmSelectPinCon(uint8_t in_pin);
    void pwmInitSingleEdgeMode(uint32_t frequency_Hz);
    void setDutyCycle(PWM_PIN pwm_pin_arg, float duty_cycle_percentage);
    void setDuty0(void);
    void setFrequency(uint32_t frequency_Hz);
};

#endif
