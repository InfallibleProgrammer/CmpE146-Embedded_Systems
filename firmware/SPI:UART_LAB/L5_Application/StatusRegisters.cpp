#include "StatusRegisters.h"


void checkReg1(StatusReg1 *a1)
{
	switch (a1->rdyBsy)
	{
	case 1: u0_dbg_printf("Device is ready\n"); break;
	case 0: u0_dbg_printf("Device is not ready\n"); break;
	}
	switch (a1->comp) {
	case 1: u0_dbg_printf("Main memory page data does not match buffer data.\n"); break;
	case 0: u0_dbg_printf("Main memory page data matches buffer data.\n"); break;
	}
	if (a1->density == 0b1011)
	{
		u0_dbg_printf("Density code matches\n");
	}
	else
	{
		u0_dbg_printf("Denasity code does NOT match\n");
	}
	switch (a1->protect)
	{
	case 1: u0_dbg_printf("Sector is protected\n"); break;
	case 0: u0_dbg_printf("Sector is not protected\n"); break;
	}
	switch (a1->pageSze)
	{
	case 1: u0_dbg_printf("Device is configured for “power of 2” binary page size (512 bytes).\n"); break;
	case 0: u0_dbg_printf("Device is configured for standard DataFlash page size (528 bytes).\n"); break;
	}

}

void checkReg2(StatusReg2 *a1)
{
	switch (a1->rdyBsy)
	{
	case 1: u0_dbg_printf("Device is ready\n"); break;
	case 0: u0_dbg_printf("Device is not ready\n"); break;
	}
	switch (a1->epe) {
	case 1: u0_dbg_printf("Erase or program error detected\n"); break;
	case 0: u0_dbg_printf("Erase or program operation was successful.\n"); break;
	}
	switch (a1->sle)
	{
	case 1: u0_dbg_printf("Sector Lockdown command is enabled\n"); break;
	case 0: u0_dbg_printf("Sector Lockdown command is disabled\n"); break;
	}
	switch (a1->ps2)
	{
	case 1: u0_dbg_printf("A sector is program suspended while using Buffer 2.\n"); break;
	case 0: u0_dbg_printf("No program operation has been suspended while using Buffer 2.\n"); break;
	}
	switch (a1->ps1)
	{
	case 0: u0_dbg_printf("No program operation has been suspended while using Buffer 1.\n"); break;
	case 1: u0_dbg_printf("A sector is program suspended while using Buffer 1."); break;
	}
	switch (a1->es)
	{
	case 1: u0_dbg_printf("A sector is erase suspended.\n"); break;
	case 0: u0_dbg_printf("No sectors are erase suspended.\n"); break;
	}
}

