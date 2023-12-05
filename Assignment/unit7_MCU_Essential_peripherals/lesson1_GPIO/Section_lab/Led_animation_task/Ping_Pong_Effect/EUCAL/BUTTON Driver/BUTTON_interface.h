/******************************************************************************
 *
 * Module: BUTTON
 *
 * Layer : EUCAL
 *
 * File Name: BUTTON_interface.h
 *
 * Description: Header file for ATMEGA32A Microcontroller - BUTTON Driver
 *
 * Author: Mohamed Demrdash
 ******************************************************************************/

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "../../utilities/STD_Types.h"

void BUTTON_init(uint8_t port,uint8_t pin);

uint8_t BUTTON_u8get_value(uint8_t port,uint8_t pin);


#endif /* BUTTON_INTERFACE_H_*/