/**
 ******************************************************************************
 * @file           : app.c
 * @author         : Mohamed Hussein Demrdash
 * @brief          : Toggel leds
 ******************************************************************************
 */

#include "platform_types.h"
#include "platform_register.h"

char arr0[5] ={1,2,3};
const char arr1[3] ={4,5,6};
char arr2[5];

int main(void)
{
	volatile uint16 i = 0 ;

	SYSCTL_RCGC2_R =0X00000020;
	for (i = 0; i < 200; i++)
	{
		/* Delay */
	}
	
	GPIOF_DIR_R   |= 1<<3;
	GPIOF_DEN_R   |= 1<<3;
	while(1)
	{
	    GPIOF_DATA_R ^= (1<<3);
		for(i = 0;i < 500 ; i++);
	}
}
