/*
 * uart.c
 *
 * Created on: Aug 17, 2023
 * Author: Mohamed Hussein Demrdash
 * 
 */

#include "platform_types.h"
#include "uart.h"


#define UART_BASE 0x101f1000

#define UART0DR   *(volatile uint32 *const)((uint32*)(UART_BASE+0x0))

void uart_send_string(const uint8 * P_tx_string)
{
    while (*P_tx_string != '\0')
    {
        UART0DR = (uint32)(*P_tx_string);
        P_tx_string++;
    }
}
