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
#include "../EUCAL/BUTTON Driver/BUTTON_interface.h"
#include "application.h"

void App_init(void)
{
	LED_InitPort('A');
}

void App_start(void)
{
	while(1)
	{
			LED_GO_BACK('A',250);		
	}
}