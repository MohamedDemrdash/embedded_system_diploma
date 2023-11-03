/*
 * File Name  : main.c
 * File Type  : Source File.
 * Layer Name : Application Layer.
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file Contain the main algorithm for the pressure monitoring project.
 * 
 */


#include "driver.h"
#include "platform_register.h"
#include "platform_types.h"
#include "alarm.h"
#include "pressure_sensor.h"

uint8 presure_sensor_read =0;
PRESSURE_STATE_t presure_state;

int main ()
{
	GPIO_INITIALIZATION();
	stop_alarm();
	while (1)
	{
		presure_sensor_read = get_sensor_value();
		presure_state = check_sensor_value(presure_sensor_read);
		if(presure_state == NOT_SAFE)
		{
			start_alarm();
			wait_alarm();
			stop_alarm();
			while(check_sensor_value(get_sensor_value()) == NOT_SAFE)
			{

			}
		}
		else
		{

		}
	}

}
