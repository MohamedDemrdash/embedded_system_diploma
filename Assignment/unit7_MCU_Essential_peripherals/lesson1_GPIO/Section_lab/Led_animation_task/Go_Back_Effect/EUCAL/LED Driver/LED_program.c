/******************************************************************************
 *
 * Module: LED
 *
 * Layer : EUCAL
 *
 * File Name: LED_interface.c
 *
 * Description: Source file for ATMEGA32A Microcontroller - LED Driver
 *
 * Author: Mohamed Demrdash
 ******************************************************************************/
//#define F_CPU 1000000UL
//#define _DELAY_BACKWARD_COMPATIBLE_
#include "Util/delay.h"
#include "../../utilities/STD_Types.h"
#include "../../MCAL/DIO Driver/DIO_interface.h"
#include "LED_interface.h"

void LED_Init(uint8_t port,uint8_t pin)
{
	DIO_set_pin_dir(port,pin,OUTPUT);
	DIO_write_pin(port,pin,LOW);
}

void LED_On(uint8_t port,uint8_t pin)
{
	DIO_write_pin(port,pin,HIGH);
}

void LED_Off(uint8_t port,uint8_t pin)
{
	DIO_write_pin(port,pin,LOW);
}

void LED_Tog(uint8_t port,uint8_t pin)
{
	DIO_toggle_pin(port,pin);
}

void LED_Flash(uint8_t port,uint8_t pin,uint32_t delay)
{
	DIO_toggle_pin(port,pin);
	_delay_ms(250);
}

void LED_InitPort(uint8_t port)
{
	DIO_set_port_dir(port,PORT_OUT);
	DIO_write_port(port,PORT_LOW);
}

void LED_FlashPort(uint8_t port,uint32_t delay)
{
	DIO_toggle_port(port);
	_delay_ms(1000);
}

void LED_ShiftLeft(uint8_t port,uint32_t delay)
{
	uint8_t pin_num;
	for (pin_num = 0;pin_num <= 7; pin_num++ )
	{
		DIO_write_pin(port,pin_num-1,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,7,LOW);
}

void LED_ShiftRight(uint8_t port,uint32_t delay)
{
	int8_t pin_num;
	for (pin_num = 7;pin_num >= 0; pin_num-- )
	{
		DIO_write_pin(port,pin_num+1,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,0,LOW);
}

void LED_Converge(uint8_t port,uint32_t delay)
{
	uint8_t pin_num;
	for (pin_num = 0;pin_num <= 3; pin_num++)
	{
		DIO_write_pin(port,pin_num-1,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		DIO_write_pin(port,8-pin_num,LOW);
		DIO_write_pin(port,7-pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,3,LOW);
	DIO_write_pin(port,4,LOW);
}

void LED_Diverge(uint8_t port,uint32_t delay)
{
	int8_t pin_num;
	for (pin_num = 3;pin_num >= 0;pin_num--)
	{
		DIO_write_pin(port,pin_num+1,LOW);
		DIO_write_pin(port,6-pin_num,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		DIO_write_pin(port,7-pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,0,LOW);
	DIO_write_pin(port,7,LOW);
}

void LED_PingPong(uint8_t port,uint32_t delay)
{
	int8_t pin_num;
	for (pin_num = 0;pin_num <= 6; pin_num++ )
	{
		DIO_write_pin(port,pin_num-1,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,6,LOW);
	for (pin_num = 7;pin_num >= 1; pin_num-- )
	{
		DIO_write_pin(port,pin_num+1,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,1,LOW);
}

void LED_SnakeEffect(uint8_t port,uint32_t delay)
{
	uint8_t pin_num;
	for (pin_num = 0;pin_num <= 7; pin_num++ )
	{
		DIO_write_pin(port,pin_num,HIGH);
		_delay_ms(250);
	}
	for (pin_num = 0;pin_num <= 7; pin_num++ )
	{
		DIO_write_pin(port,pin_num,LOW);
		_delay_ms(250);
	}
}

void LED_Converge_Diverge(uint8_t port,uint32_t delay)
{
	int8_t pin_num;
	for (pin_num = 0;pin_num <= 3; pin_num++)
	{
		DIO_write_pin(port,pin_num-1,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		DIO_write_pin(port,8-pin_num,LOW);
		DIO_write_pin(port,7-pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,3,LOW);
	DIO_write_pin(port,3,LOW);
	for (pin_num = 3;pin_num >= 0; pin_num--)
	{
		DIO_write_pin(port,pin_num+1,LOW);
		DIO_write_pin(port,6-pin_num,LOW);
		DIO_write_pin(port,pin_num,HIGH);
		DIO_write_pin(port,7-pin_num,HIGH);
		_delay_ms(250);
	}
	DIO_write_pin(port,0,LOW);
	DIO_write_pin(port,7,LOW);
}

void LED_GO_BACK(uint8_t port,uint32_t delay)
{
	sint8_t pin_num;
	for (pin_num = 0;pin_num <= 7; pin_num++ )
	{
		DIO_write_pin(port,pin_num,HIGH);
		_delay_ms(250);
	}
	for (pin_num = 7;pin_num >= 0; pin_num-- )
	{
		DIO_write_pin(port,pin_num,LOW);
		_delay_ms(250);
	}
}