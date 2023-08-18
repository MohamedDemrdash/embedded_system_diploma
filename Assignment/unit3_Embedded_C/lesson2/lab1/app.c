/*
 * app.c
 *
 * Created on: Aug 17, 2023
 * Author: Mohamed Hussein Demrdash
 * 
 */

#include "platform_types.h"
#include "uart.h"

const sint32 x;
uint8 str[100] = "learn in depth: Demrdash";

void main(void)
{
    uart_send_string(str);
}