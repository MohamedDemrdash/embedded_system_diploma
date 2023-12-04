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
	//Configure the Bit_3 at Port D to be input (INT1)
	DDRD &= ~(1<<3);
	
	//Configure the Bit_0 at Port B to be output for the led
	DDRB |= (1<<0);
}

void EXTI_INIT(void)
{
	//Configure the EXTI 1 to be triggered with rising edge
	MCUCR |= (0B11 << 2);

	//Enable the global interrupt bit at the status register
	SREG |= (1<<7);
	
	//Enable the interrupt for the EXTI 1
	GICR |= (1<<7);
	
}

int main(void)
{
    GPIO_INIT();
	EXTI_INIT();
    while (1) 
    {
		
    }
}




//void EXT_INT1(void)
ISR(INT1_vect)
{
	//The flag Bit of EXTI 1 will be cleared by hardware
	
	//Toggle the output at pin_0 at port B
	PORTB ^= (1<<0);
	_delay_ms(1000);
	PORTB ^= (1<<0);
	
}

