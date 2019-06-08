#include <stdint.h>
#include <stdio.h>
#include "LabGPIO.h"



int main(void)
{

    printf("What port do you want");
    scanf("%i", port);
    printf("What pin do you want");
    scanf("%i", pin);
    LabGPIO LabGPIO(port,pin);
    LabGPIO.setAsOutput();
    while(1==1){
        LabGPIO.set(1);
        delay_ms(5000);
        LabGPIO.set(0);
        delay_ms(5000);
    }


}