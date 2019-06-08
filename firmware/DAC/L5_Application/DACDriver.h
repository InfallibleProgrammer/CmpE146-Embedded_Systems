#ifndef DAC_DRIVER_H_
#define DAC_DRIVER_H_

#include <stdio.h>
#include "LPC17xx.h"
#include "stdint.h"

class DACDriver
{
public:
	enum DAC_PIN
	{
		DAC_PIN_0_25,
		DAC_PIN_0_26,
		DAC_PIN_1_30,
		DAC_PIN_1_31,
	};
	DACDriver();
	~DACDriver();
	void initDAC(DAC_PIN dac_pin, bool mA_350);
	float DAC_conversion(uint16_t value);
private:
};

#endif