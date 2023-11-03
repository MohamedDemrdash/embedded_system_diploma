/*
 * File Name  : driver.c
 * File Type  : Source File.
 * Layer Name : Microcontroller Abstraction Layer (MCAL).
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file has the prototypes of some of STM32F103C6 intelnal modules.
 * 
 */

#include "driver.h"
#include "platform_register.h"
#include "platform_types.h"

void Delay(uint32 nCount)
{
	for(; nCount != 0; nCount--);
}

uint8 get_port_value()
{
	return (GPIOA_IDR & 0xFF);
}

void Set_pin_value(uint8 i,uint8 pin)
{
	if (i == 1){
		SET_BIT(GPIOA_ODR,pin);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,pin);
	}
}

uint8 get_pin_value(uint8 pin)
{
	return (READ_BIT(GPIOA_IDR,pin));
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}