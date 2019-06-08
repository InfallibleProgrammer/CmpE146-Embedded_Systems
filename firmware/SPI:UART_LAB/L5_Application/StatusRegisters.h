#include "printf_lib.h"
#include <stdint.h>
#include <stdio.h>


#ifndef StatusReg
#define StatusReg
typedef union
{
	uint8_t status_register;
	struct
	{
		uint8_t pageSze: 1;
		uint8_t protect: 1;
		uint8_t density: 4;
		uint8_t comp: 1;
		uint8_t rdyBsy: 1;

	} __attribute__((packed));
} StatusReg1;

typedef union
{
	uint8_t status_register;
	struct
	{
		uint8_t es: 1;
		uint8_t ps1: 1;
		uint8_t ps2: 1;
		uint8_t sle: 1;
		uint8_t DONOTUSE1: 1;
		uint8_t epe: 1;
		uint8_t DONOTUSE2: 1;
		uint8_t rdyBsy: 1;
	} __attribute__((packed));
} StatusReg2;

void checkReg1(StatusReg1 *a1);
void checkReg2(StatusReg2 *a1);

#endif