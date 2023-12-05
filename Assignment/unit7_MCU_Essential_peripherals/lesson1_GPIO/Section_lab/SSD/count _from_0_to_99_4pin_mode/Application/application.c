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
#define F_CPU 8000000UL
#include "util/delay.h"
#include "application.h"



SSD_Type SSD1 ={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTB,7};	
SSD_Type SSD2 ={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTB,6};	
SW_Type SW1 = {SW_PORTC,0,SW_PULL_DOWN};
	
void App_init(void)
{
	SSD_voidInitialDataPort(SSD1);
	SSD_voidInitialDataPort(SSD2);
	SSD_voidEnable(SSD2);
	SW_VoidInit(SW1);
}

void App_start(void)
{
	uint8_t i =0 ;
	while(1)
	{
		for(uint32_t j =0 ;j <= 40;j++)
		{
			
			SSD_voidSendNumber(SSD1,i%10);
			SSD_voidEnable(SSD1);
			_delay_ms(10);
			//SSD_voidSendNumber(SSD1,i%10);
			SSD_voidDisable(SSD1);
			SSD_voidSendNumber(SSD2,i/10);
			SSD_voidEnable(SSD2);
			_delay_ms(10);
			//SSD_voidSendNumber(SSD2,i/10);
			SSD_voidDisable(SSD2);

		}
			i++;
	}
}