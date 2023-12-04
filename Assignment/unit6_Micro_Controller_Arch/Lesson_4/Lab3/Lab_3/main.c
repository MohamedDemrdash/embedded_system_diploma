/*
 * Lab_3.c
 *
 * Created: 12/4/2023 10:06:54 AM
 * Author : Mohamed Hussein Demrdash
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

void GPIO_INIT(void)
{
	
	//Configure the Bit_2 at Port D to be input EXTI 0
	DDRD &= ~(1<<2);
	
	//Configure the Bit_3 at Port D to be input EXTI 1
	DDRD &= ~(1<<3);
	
	//Configure the Bit_2 at Port b to be input EXTI 2
	DDRB &= ~(1<<2);
	
	//Configure the Bit_0 at Port 0 to be output for EXTI 0
	DDRA |= (1<<0);
	
	//Configure the Bit_0 at Port 1 to be output for EXTI 1
	DDRA |= (1<<1);
	
	//Configure the Bit_0 at Port 2 to be output for EXTI 2
	DDRA |= (1<<2);
}

void EXTI_INIT(void)
{
	//Configure the EXTI 0 to be triggered with any logical change
	MCUCR |= (0B01 << 0);
	
	//Configure the EXTI 1 to be triggered with rising edge
	MCUCR |= (0B11 << 2);

	//Configure the EXTI 2 to be triggered with falling edge
	MCUCSR &= ~(1 << 6);
	
	//Enable the global interrupt bit at the status register
	SREG |= (1<<7);
	
	//Enable the interrupt for the EXTI 0
	GICR |= (1<<6);
	
	//Enable the interrupt for the EXTI 1
	GICR |= (1<<7);
	
	//Enable the interrupt for the EXTI 2
	GICR |= (1<<5);
}

int main(void)
{
    GPIO_INIT();
	EXTI_INIT();
    while (1) 
    {
		
    }
}


ISR(INT0_vect)
{
	//The flag Bit of EXTI 0 will be cleared by hardware
	
	//Toggle the output at pin_0 at port A
	PORTA ^= (1<<0);
	_delay_ms(1000);
	PORTA ^= (1<<0);
	
}


//void EXT_INT1(void)
ISR(INT1_vect)
{
	//The flag Bit of EXTI 1 will be cleared by hardware
	
	//Toggle the output at pin_1 at port A
	PORTA ^= (1<<1);
	_delay_ms(1000);
	PORTA ^= (1<<1);
}

ISR(INT2_vect)
{
	//The flag Bit of EXTI 2 will be cleared by hardware
	
	//Toggle the output at pin_2 at port A
	PORTA ^= (1<<2);
	_delay_ms(1000);
	PORTA ^= (1<<2);
	
}
