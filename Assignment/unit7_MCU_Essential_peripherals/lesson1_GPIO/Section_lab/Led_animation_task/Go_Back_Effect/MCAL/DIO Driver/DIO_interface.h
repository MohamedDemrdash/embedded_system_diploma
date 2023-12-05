/*
 * DIO_interface.h
 *
 * Created: 2/6/2023 9:21:31 PM
 *  Author: Mohamed Demrdash
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../utilities/STD_Types.h"

#define  PORT_OUT    0xFF
#define  PORT_IN     0x00

#define  PORT_HIGH   0xFF
#define  PORT_LOW    0x00

void DIO_set_pin_dir(uint8_t port,uint8_t pin,uint8_t dir);

void DIO_write_pin(uint8_t port,uint8_t pin,uint8_t val);

void DIO_toggle_pin(uint8_t port,uint8_t pin);

uint8_t DIO_u8read_pin(uint8_t port,uint8_t pin);

void DIO_set_port_dir(uint8_t port,uint8_t val);

void DIO_write_port(uint8_t port,uint8_t val);

unsigned DIO_u8read_port(uint8_t port);

void DIO_toggle_port(uint8_t port);



#endif /* DIO_INTERFACE_H_ */