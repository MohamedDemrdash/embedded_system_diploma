/******************************************************************************
 *
 * Layer : Application
 *
 * File Name: Application.c
 *
 * Description: Source file for ATMEGA32A Microcontroller - Application
 *
 * Author: Mohamed Demrdash
 ******************************************************************************/
#include "../utilities/STD_Types.h"
#include "../EUCAL/LED Driver/LED_interface.h"
#include "../EUCAL/BUTTON Driver/SW_interface.h"
#include "../EUCAL//SSD Driver/SSD_interface.h"
#include "util/delay.h"
#include "application.h"


SSD_Type SSD1 ={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTB,7};	
SSD_Type SSD2 ={SSD_COMMON_CATHODE,SSD_PORTA,SSD_PORTB,7};	
	
void App_init(void)
{
	SSD_voidInitialDataPort(SSD1);
	SSD_voidEnable(SSD1);
	SSD_voidInitialDataPort(SSD2);
	SSD_voidEnable(SSD2);
}

void App_start(void)
{
	uint8_t i =0;
	while(1)
	{
		for(i =0 ; i <=99;i++)
		{
			SSD_voidSendNumber(SSD1,i);
			SSD_voidSendNumber(SSD2,i/10);
			_delay_ms(200);
		}
	}
}