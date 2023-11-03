/*
 * File Name  : pressure_sensor.c
 * File Type  : Source File.
 * Layer Name : Hardware Abstraction layer(HAL).
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file has the function defination of pressure sensore module.
 * 
 */
#include "pressure_sensor.h"
#include "platform_register.h"
#include "platform_types.h"
#include "driver.h"


uint8 get_sensor_value()
{
    return (get_port_value());
}

PRESSURE_STATE_t check_sensor_value(uint8 sensor_value)
{
    PRESSURE_STATE_t presssure_state;
    if(sensor_value < PRESSURE_THRESHOLD)
    {
        presssure_state = SAFE;
    }
    else
    {
        presssure_state = NOT_SAFE;
    }

    return presssure_state;
}