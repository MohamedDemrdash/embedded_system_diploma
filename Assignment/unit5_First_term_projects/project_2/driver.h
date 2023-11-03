/*
 * File Name  : driver.h
 * File Type  : Header File.
 * Layer Name : Microcontroller Abstraction Layer (MCAL).
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file has the prototypes of some of STM32F103C6 intelnal modules.
 * 
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include "platform_register.h"
#include "platform_types.h"


void Delay(uint32 nCount);
uint8   get_port_value();
void    Set_pin_value(uint8 i,uint8 pin);
uint8   get_pin_value(uint8 pin);
void    GPIO_INITIALIZATION();

#endif /* DRIVER_H_ */