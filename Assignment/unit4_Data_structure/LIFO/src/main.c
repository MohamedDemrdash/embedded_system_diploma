/*
 ============================================================================
 Name        : main.c
 Author      : Mohamed Demrdash
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

uint16 g_arr[4];

int main(void) {

	uint16 op;

	LIFO_buffer UART_fifo;
	LIFO_init(&UART_fifo,g_arr,4);
	while(1)
	{
		printf("1-add  2-get 3-is full 4-is empty 5-display\n");
		fflush(stdin);
		fflush(stdout);
		scanf(" %d",&op);
//		op = arr[i];
//		i++;
		uint16 item;
		switch(op)
		{
		case 1:
			printf("ADD new item\n");
			fflush(stdin);
			fflush(stdout);
			scanf(" %hu",&item);
			LIFO_add(&UART_fifo,item);
			break;
		case 2:
			printf("Remove an item\n");
			LIFO_get(&UART_fifo,&item);
			printf("%d\n",item);
			break;
		case 3:
			if(LIFO_is_full(&UART_fifo) == LIFO_FULL)
			{
				printf("yes\n");
			}
			else
			{
				printf("NO\n");
			}
			break;
		case 4:
			if(LIFO_is_empty(&UART_fifo) == LIFO_EMPTY)
						{
							printf("yes\n");
						}
						else
						{
							printf("NO\n");
						}

			break;
		case 5:
			LIFO_display(&UART_fifo);
			break;
		}
	}

	return EXIT_SUCCESS;
}
