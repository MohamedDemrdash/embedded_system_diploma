/*
 * File Name  : platform_register.h
 * File Type  : Header File.
 * Layer Name : Services layer.
 * Created on : Aug 14, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file define all macros realted to STM32F103C6 registers.
 * 
 */

#ifndef PLATFORM_REGISTER_H_
#define PLATFORM_REGISTER_H_

#include "platform_types.h"

#define SET_BIT(ADDRESS, BIT)     ADDRESS |=  (1 << BIT)
#define RESET_BIT(ADDRESS, BIT)   ADDRESS &= ~(1 << BIT)
#define TOGGLE_BIT(ADDRESS, BIT)  ADDRESS ^=  (1 << BIT)
#define READ_BIT(ADDRESS, BIT)  ((ADDRESS >> (BIT)) & 1)

#define GPIO_PORTA  0x40010800
#define BASE_RCC    0x40021000

#define APB2ENR     *(volatile uint32 *)(BASE_RCC + 0x18)

#define GPIOA_CRL   *(volatile uint32 *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH   *(volatile uint32 *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR   *(volatile uint32 *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR   *(volatile uint32 *)(GPIO_PORTA + 0x0C)

#endif /* PLATFORM_REGISTER_H_ */
