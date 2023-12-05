/******************************************************************************
 *
 * Module: LED
 *
 * Layer : EUCAL
 *
 * File Name: LED_interface.h
 *
 * Description: Header file for ATMEGA32A Microcontroller - LED Driver
 *
 * Author: Mohamed Demrdash
 ******************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../utilities/STD_Types.h"


void LED_Init(uint8_t port,uint8_t pin);

void LED_On(uint8_t port,uint8_t pin);

void LED_Off(uint8_t port,uint8_t pin);

void LED_Tog(uint8_t port,uint8_t pin);

void LED_Flash(uint8_t port,uint8_t pin,uint32_t delay);

void LED_InitPort(uint8_t port);

void LED_FlashPort(uint8_t port,uint32_t delay);

void LED_ShiftLeft(uint8_t port,uint32_t delay);

void LED_ShiftRight(uint8_t port,uint32_t delay);

void LED_Converge(uint8_t port,uint32_t delay);

void LED_Diverge(uint8_t port,uint32_t delay);

void LED_PingPong(uint8_t port,uint32_t delay);

void LED_SnakeEffect(uint8_t port,uint32_t delay);

void LED_Converge_Diverge(uint8_t port,uint32_t delay);

void LED_GO_BACK(uint8_t port,uint32_t delay);


#endif /* LED_INTERFACE_H_*/