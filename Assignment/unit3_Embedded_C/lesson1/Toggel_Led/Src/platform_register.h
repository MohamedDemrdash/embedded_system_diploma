/*
 * platform_register.h
 *
 * Created on: Aug 14, 2023
 * Author: Mohamed Hussein Demrdash
 *
 */

#ifndef PLATFORM_REGISTER_H_
#define PLATFORM_REGISTER_H_

#include "platform_types.h"

#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800

#define RCC_APB2ENR  *(volatile uint32*)(RCC_BASE + 0x14)

#define GPIOA_CRH    *(volatile uint32*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(volatile uint32*)(GPIOA_BASE + 0x0c)

#endif /* PLATFORM_REGISTER_H_ */
