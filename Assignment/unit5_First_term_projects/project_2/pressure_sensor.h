/*
 * File Name  : pressure_sensor.h
 * File Type  : Header File.
 * Layer Name : Hardware Abstraction layer(HAL).
 * Created on : Aug 14, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file has the function prototypes of pressure sensore module.
 * 
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "platform_register.h"
#include "platform_types.h"

#define PRESSURE_THRESHOLD 20

typedef enum 
{
    SAFE,
    NOT_SAFE
}PRESSURE_STATE_t;

uint8 get_sensor_value();

PRESSURE_STATE_t check_sensor_value(uint8 sensor_value);


#endif /*PRESSURE_SENSOR_H_*/