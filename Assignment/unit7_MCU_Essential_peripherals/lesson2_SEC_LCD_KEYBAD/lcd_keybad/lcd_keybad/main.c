/*
 * lcd_keypad.c
 *
 * Created: 12/10/2023 10:30:30 PM
 * Author : Mohamed Demrdash
 */ 

#include <avr/io.h>
#include "LCD_driver/LCD.h"
#include "KEYPAD_diver/KEYPAD.h"

int main(void)
{
	LCD_INIT();
	Keypad_init();
	_delay_ms(50);
	uint8_t key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			LCD_clear_screen();
			break;
			default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}
	}
}

