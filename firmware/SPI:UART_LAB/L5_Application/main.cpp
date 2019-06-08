// /*
//  *     SocialLedge.com - Copyright (C) 2013
//  *
//  *     This file is part of free software framework for embedded processors.
//  *     You can use it and/or distribute it as long as this copyright header
//  *     remains unmodified.  The code is free for personal use and requires
//  *     permission to use in a commercial product.
//  *
//  *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
//  *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
//  *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
//  *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
//  *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
//  *
//  *     You can reach the author of this software at :
//  *          p r e e t . w i k i @ g m a i l . c o m
//  */

// /**
//  * @file
//  * @brief This is the application entry point.
//  */
// #include <stdint.h>
// #include <stdio.h>
// #include "utilities.h"
// #include "io.hpp"
// #include "tasks.hpp"
// #include "ADCDriver.h"
// #include "PWMDriver.h"
// #include "LabGPIO.h"
// #include "LabGPIOInterrupts.h"
// #include "LabSPI.h"
// #include "StatusRegisters.h"


// StatusReg2 Reg2;
// StatusReg1 Reg1;

// LabSPI SPIFlash;
// LabGPIO FlashSel(6, 0);

// void cs();
// void ds();
// SemaphoreHandle_t SPI_lock = xSemaphoreCreateMutex();




// void task_sig_reader(void *p)
// {
//  char manu_id, device_id1, device_id2;
//  SPIFlash.init(LabSPI::SSP1, 8, LabSPI::SPI, 48); //use SSP1, 8 bits data, SPI data format, divid by 48.
//  while (1)
//  {
//      if (xSemaphoreTake(SPI_lock, portMAX_DELAY)) {
//          cs();

//          SPIFlash.transfer(0x9F); //send opcode to get manu id and device id.
//          manu_id = SPIFlash.transfer(0xAA); //send garbage value
//          device_id1 = SPIFlash.transfer(0xAA); //send garbage value
//          device_id2 = SPIFlash.transfer(0xE1); //send garbage value

//          u0_dbg_printf("Manufacture ID: %x\n", manu_id);
//          u0_dbg_printf("DeviceID1: %x\n", device_id1);
//          u0_dbg_printf("DeviceID2: %.2x\n", device_id2);
//          ds();
//          cs();
//          SPIFlash.transfer(0xD7);
//          Reg1.status_register = SPIFlash.transfer(0x00);
//          Reg2.status_register = SPIFlash.transfer(0x00);
//          u0_dbg_printf("************Status Reg************\n");
//          u0_dbg_printf("Reg1: %x\n", Reg1.status_register);
//          u0_dbg_printf("Reg2: %x\n", Reg2.status_register);
//          checkReg1(&Reg1);
//          checkReg2(&Reg2);
//          ds();
//          xSemaphoreGive(SPI_lock);
//          vTaskDelay(1000);
//      }
//  }
// }


// int main(void)
// {
//  xTaskCreate(task_sig_reader, "vTask1", 2048, NULL, 3, NULL);
//  scheduler_add_task(new terminalTask(PRIORITY_HIGH));
//  vTaskStartScheduler();
// }

// void cs()
// {
//  FlashSel.setAsOutput();
//  FlashSel.setLow();
// }

// void ds() {
//  FlashSel.setAsOutput();
//  FlashSel.setHigh();
// }

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
 *          FreeRTOS and stdio printf is pre-configured to use uart0_min.h before main() enters.
 *          @see L0_LowLevel/lpc_sys.h if you wish to override printf/scanf functions.
 *
 */
#include "tasks.hpp"
//#include "examples/examples.hpp"
#include "FreeRTOS.h"
#include "LPC17xx.h"
#include "semphr.h"
#include "queue.h"
#include "labuart.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdio.h>
#include "printf_lib.h"
void vALUMachine(void * pvParameters);
void vSendALUCommand(void * pvParamters);
void vResults(void * pvParamters);
void readUARTData();
void readUARTData2();
void RxInterruptHandler2();
void RxInterruptHandler3();
QueueHandle_t rx_q;
LabUART UART_BUS;
char ALUcmd[3];
bool ALUready = false;
/**
 * The main() creates tasks or "threads".  See the documentation of scheduler_task class at scheduler_task.hpp
 * for details.  There is a very simple example towards the beginning of this class's declaration.
 *
 * @warning SPI #1 bus usage notes (interfaced to SD & Flash):
 *      - You can read/write files from multiple tasks because it automatically goes through SPI semaphore.
 *      - If you are going to use the SPI Bus in a FreeRTOS task, you need to use the API at L4_IO/fat/spi_sem.h
 *
 * @warning SPI #0 usage notes (Nordic wireless)
 *      - This bus is more tricky to use because if FreeRTOS is not running, the RIT interrupt may use the bus.
 *      - If FreeRTOS is running, then wireless task may use it.
 *        In either case, you should avoid using this bus or interfacing to external components because
 *        there is no semaphore configured for this bus and it should be used exclusively by nordic wireless.
 */


int main(void)
{
	const uint32_t STACK_SIZE = 1024;
	const uint8_t QUEUE_SIZE = 5;
	uint16_t baud_rate = 9600;
	rx_q = xQueueCreate(QUEUE_SIZE, 3);
	if (rx_q != NULL)
	{
		UART_BUS.init(LabUART::UART3, 8, baud_rate, RxInterruptHandler3);
		//UART_BUS.init(LabUART::UART2, 8, baud_rate, RxInterruptHandler2);
		//xTaskCreate(vALUMachine, "UART_ALU", STACK_SIZE, NULL, 1, NULL);
		// xTaskCreate(vResults, "UART_RX", STACK_SIZE, NULL, 1, NULL);
		// scheduler_add_task(new terminalTask(PRIORITY_HIGH));
		xTaskCreate(vSendALUCommand, "UART_TX", STACK_SIZE, NULL, 1, NULL);
		scheduler_add_task(new terminalTask(PRIORITY_HIGH));
	}

	scheduler_start(); ///< This shouldn't return
	return -1;
}
void vALUMachine(void * pvParameters)
{
	uint8_t i = 0, rx_data = 0;
	uint16_t result = 0;
	std::string sendResult = "";
	u0_dbg_printf("Inside ALU Machine\n");
	while (1)
	{
		if (xQueueReceive(rx_q, &rx_data, portMAX_DELAY))
		{
			//u0_dbg_printf("integer i: %i\n", i);
			ALUcmd[i] = rx_data;
			//u0_dbg_printf("\nI am here: %i",ALUcmd[i]);
			if (i == 2)
			{
				//u0_dbg_printf("ALUcmd: %i", ALUcmd[2]);
				if (ALUcmd[2] == '+' || ALUcmd[2] == '-' || ALUcmd[2] == '*')
				{
					ALUready = true;
				}
				i = 0;
			}
			i++;
		}
		if (ALUready)
		{
			u0_dbg_printf("ALU is here\n\n");
			switch (ALUcmd[2])
			{
			case '+':
				result = (int)(ALUcmd[0]) + ((int) ALUcmd[1]);
				break;
			case '-':
				result = (int)(ALUcmd[0]) - ((int) ALUcmd[1]);
				break;
			case '*':
				result = (int)(ALUcmd[0]) * ((int) ALUcmd[1]);
				break;
			default:
				break;
			}
			memset(&ALUcmd, 0, sizeof(ALUcmd));
			UART_BUS.tx(result);
			printf("This is the result: %d", result);
			result = 0;
			i = 0;
			ALUready = false;
		}
	}
}
void vSendALUCommand(void * pvParamters)
{
	vTaskDelay(1000);
	uint8_t rx_data = 0;
	uint8_t result = 0;
	while (1)
	{
		UART_BUS.tx(5);
		UART_BUS.tx(7);
		UART_BUS.tx('+');
		printf("57+\n");
		if (xQueueReceive(rx_q, &rx_data, portMAX_DELAY)) {
			result = rx_data;
			u0_dbg_printf("Result: %i\n", result);
		}
		vTaskDelay(1000);
	}
}



void RxInterruptHandler2()
{
	if ((LPC_UART2->IIR & 1) == 0) {
		uint8_t byte = UART_BUS.rx();
		xQueueSendFromISR(rx_q, &byte, NULL);
	}
}

void RxInterruptHandler3()
{
	u0_dbg_printf("I made it to the handler\n\n");
	if ((LPC_UART3->IIR & 1) == 0) {
		uint8_t byte = UART_BUS.rx();
		xQueueSendFromISR(rx_q, &byte, NULL);
	}
}
