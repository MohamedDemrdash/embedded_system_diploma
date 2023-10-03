/**
 ******************************************************************************
 * @file           : app.c
 * @author         : Mohamed Hussein Demrdash
 * @brief          : Toggel leds
 ******************************************************************************
 */

#include "platform_types.h"
#include "platform_register.h"

char arr0[3] ={1,2,3};
const char arr1[3] ={4,5,6};
char arr2[4];

int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH   &= 0XFF0FFFFF;
	GPIOA_CRH   |= 0X00200000;
    uint16 i = 0 ;
	while(1)
	{
	    GPIOA_ODR ^= 1<<13;
		for(i = 0;i < 1000 ; i++);
	}
}
