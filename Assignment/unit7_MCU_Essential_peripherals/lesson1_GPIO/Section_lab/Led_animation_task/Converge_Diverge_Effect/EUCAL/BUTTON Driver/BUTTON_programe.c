/******************************************************************************
 *
 * Module: BUTTON
 *
 * Layer : EUCAL
 *
 * File Name: BUTTON_program.c
 *
 * Description: Source file for ATMEGA32A Microcontroller - BUTTON Driver
 *
 * Author: Mohamed Demrdash
 ******************************************************************************/
#include "../../utilities/STD_Types.h"
#include "BUTTON_interface.h"
#include "../../MCAL/DIO Driver/DIO_interface.h"

void BUTTON_init(uint8_t port,uint8_t pin)
{
	DIO_write_pin(port,pin,INPUT);
}

uint8_t BUTTON_u8get_value(uint8_t port,uint8_t pin)
{
	uint8_t value = DIO_u8read_pin(port,pin);
	return value; 
}

