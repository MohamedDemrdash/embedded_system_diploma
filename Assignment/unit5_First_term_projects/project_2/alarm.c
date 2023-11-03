/*
 * File Name  : alarm.c
 * File Type  : Source File.
 * Layer Name : Hardware Abstraction layer(HAL).
 * Created on : Aug 14, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file define function's defintion of the alarm module.
 * 
 */

#include "alarm.h"
#include "driver.h"
#include "pressure_sensor.h"
#include "platform_register.h"
#include "platform_types.h"

void start_alarm()
{
    Set_pin_value(ALARM_ON,ALARM_PIN);
}
void wait_alarm()
{
    Delay(ALARM_DURATION); 
}
void stop_alarm()
{
    Set_pin_value(ALARM_OFF,ALARM_PIN);
}

ALARM_STATE_t get_alarm_state()
{
    ALARM_STATE_t alarm_state;
    if(get_pin_value(ALARM_ON))
    {
        alarm_state = ALARM_STATE_ON;
    }
    else
    {
        alarm_state = ALARM_STATE_OFF;
    }

    return alarm_state;
}