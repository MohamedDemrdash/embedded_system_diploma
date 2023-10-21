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

#define SYSCTL_BASE    0x400FE000
#define GPIOF_BASE  0x40025000

#define SYSCTL_RCGC2_R    *(volatile uint32*)(SYSCTL_BASE   + 0x108)

#define GPIOF_DATA_R      *(volatile uint32*)(GPIOF_BASE + 0x3Fc)
#define GPIOF_DIR_R       *(volatile uint32*)(GPIOF_BASE + 0x400)
#define GPIOF_DEN_R       *(volatile uint32*)(GPIOF_BASE + 0x51c)


#endif /* PLATFORM_REGISTER_H_ */
