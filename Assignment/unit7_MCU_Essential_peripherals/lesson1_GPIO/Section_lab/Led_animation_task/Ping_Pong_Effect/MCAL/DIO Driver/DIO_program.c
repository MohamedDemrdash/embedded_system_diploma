/*
 * DIO_program.c
 *
 * Created: 2/6/2023 9:20:05 PM
 *  Author: Mohamed Demrdash
 */ 

#include "../../utilities/REGISTER.h"
#include "../../utilities/STD_Types.h"
#include "../../utilities/BIT_Math.h"
#include "DIO_interface.h"

void DIO_set_pin_dir(uint8_t port,uint8_t pin,uint8_t dir)
{
	switch (port)
	{
		case 'A' :
		case 'a' :
		{
			if(dir != 0)
			{
				SET_BIT(DDRA,pin);
			}
			else
			{
				CLEAR_BIT(DDRA,pin);
			}
			break;
		}
		case 'B' :
		case 'b' :
		{
			if(dir != 0)
			{
				SET_BIT(DDRB,pin);
			}
			else
			{
				CLEAR_BIT(DDRB,pin);
			}
			break;
		}
		case 'C' :
		case 'c' :
		{
			if(dir != 0)
			{
				SET_BIT(DDRC,pin);
			}
			else
			{
				CLEAR_BIT(DDRC,pin);
			}
			break;
		}
		case 'D' :
		case 'd' :
		{
			if(dir != 0)
			{
				SET_BIT(DDRD,pin);
			}
			else
			{
				CLEAR_BIT(DDRD,pin);
			}
			break;
		}		
	}
}

void DIO_write_pin(uint8_t port,uint8_t pin,uint8_t val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		{
			if(val != 0)
			{
				SET_BIT(PORTA,pin);
			}
				else
			{
				CLEAR_BIT(PORTA,pin);
			}
			break;			
		}
		case 'B':
		case 'b':
		{
			if(val != 0)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLEAR_BIT(PORTB,pin);
			}
			break;		
		}
		case 'C':
		case 'c':
		{
			if(val != 0)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLEAR_BIT(PORTC,pin);
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if(val != 0)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLEAR_BIT(PORTD,pin);
			}
			break;
		}
	}
}

void DIO_toggle_pin(uint8_t port,uint8_t pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
			TOG_BIT(PORTA,pin);
			break;
		case 'B':
		case 'b':
			TOG_BIT(PORTB,pin);
			break;
		case 'C':
		case 'c':
			TOG_BIT(PORTC,pin);
			break;
		case 'D':
		case 'd':
			TOG_BIT(PORTD,pin);
			break;	
	}	
}

uint8_t DIO_u8read_pin(uint8_t port,uint8_t pin)
{
	unsigned char val;
	switch(port)
	{
		case 'A':
		case 'a':
			val = READ_BIT(PINA,pin);
			break;
		case 'B':
		case 'b':
		val = READ_BIT(PINB,pin);
		break;
		case 'C':
		case 'c':
		val = READ_BIT(PINC,pin);
		break;
		case 'D':
		case 'd':
		val = READ_BIT(PIND,pin);
		break;
	}
	return val;
}

void DIO_set_port_dir(uint8_t port,uint8_t val)
{
	switch(port)
	{
		case 'A':
		case 'a':
			DDRA = val;
			break;
		case 'B':
		case 'b':
			DDRB = val;
			break;
		case 'C':
		case 'c':
			DDRC = val;
			break;
		case 'D':
		case 'd':
			DDRD = val;
			break;
	}
}

void DIO_write_port(uint8_t port,uint8_t val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA = val;
		break;
		case 'B':
		case 'b':
		PORTB = val;
		break;
		case 'C':
		case 'c':
		PORTB = val;
		break;
		case 'D':
		case 'd':
		PORTD = val;
		break;
	}
}

unsigned DIO_u8read_port(uint8_t port)
{
	unsigned char val;
	switch(port)
	{
		case 'A':
		case 'a':
			val = PINA;
			break;
		case 'B':
		case 'b':
			val = PINB;
			break;
		case 'C':
		case 'c':
			val = PINC;
			break;
		case 'D':
		case 'd':
			val = PIND;
			break;
	}
	return val;
}

void DIO_toggle_port(uint8_t port)
{
	switch(port)
	{
		case 'A':
		case 'a':
			PORTA ^= 0xFF;
			break;
		case 'B':
		case 'b':
			PORTB ^= 0xFF;
			break;
		case 'C':
		case 'c':
			PORTC ^= 0xFF;
			break;
		case 'D':
		case 'd':
			PORTD ^= 0xFF;
			break;
	}
}