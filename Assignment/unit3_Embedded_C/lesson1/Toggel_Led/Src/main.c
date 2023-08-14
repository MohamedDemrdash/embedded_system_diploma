/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Hussein Demrdash
 * @brief          : Toggel leds
 ******************************************************************************
 */

#include "platform_types.h"
#include "platform_register.h"

int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH   &= 0XFF0FFFFF;
	GPIOA_CRH   |= 0X00200000;
    uint16 i = 0 ;
	while(1)
	{
	    GPIOA_ODR ^= 1<<13;
		for(i = 0;i < 500 ; i++);
	}
}
