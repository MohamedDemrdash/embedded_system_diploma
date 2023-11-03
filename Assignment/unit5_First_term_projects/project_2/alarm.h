/*
 * File Name  : alarm.h
 * File Type  : Header File.
 * Layer Name : Hardware Abstraction layer(HAL).
 * Created on : Aug 14, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file define function's prototype of the alarm module.
 * 
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "platform_register.h"
#include "platform_types.h"

#define ALARM_DURATION   2000000 //this number must be calculated based on the clock to simulate 60 Sec of the real time. 

#define ALARM_ON  0
#define ALARM_OFF 1
#define ALARM_PIN 13

typedef enum
{
    ALARM_STATE_OFF,
    ALARM_STATE_ON
}ALARM_STATE_t;

void          start_alarm();
void          wait_alarm();
void          stop_alarm();
ALARM_STATE_t get_alarm_state(); 


#endif /*ALARM_H_*/