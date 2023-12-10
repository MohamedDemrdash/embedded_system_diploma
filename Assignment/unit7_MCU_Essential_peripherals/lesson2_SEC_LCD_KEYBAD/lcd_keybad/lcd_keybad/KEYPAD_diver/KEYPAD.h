/*
 * KEYBAD.h
 *
 * Created: 12/10/2023 10:42:45 PM
 *  Author: moham
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT			PORTD
#define DataDir_KEYPAD_PORT DDRD
#define keypadPIN			PIND

void Keypad_init();
char Keypad_getkey();


#endif /* KEYBAD_H_ */