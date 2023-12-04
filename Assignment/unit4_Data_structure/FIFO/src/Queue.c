/*
 ============================================================================
 Name        : Queue.c
 Author      : Mohamed Demrdash
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main(void) {

	uint8 op;
	uint8 item;
	FIFO_INIT(UART,5);
	while(1)
	{
		printf("1-add  2-get 3-is full 4-is empty 5-display\n");
		fflush(stdin);
		fflush(stdout);
		scanf(" %d",&op);

		switch(op)
		{
		case 1:
			printf("ADD new item\n");
			fflush(stdin);
			//fflush(stdout);
			scanf("%d",&item);
			FIFO_enqueue(&UART_fifo,item);
			break;
		case 2:
			printf("Remove an item\n");
			FIFO_dequeue(&UART_fifo,&item);
			printf("%d\n",item);
			break;
		case 3:
			if(FIFO_is_full(&UART_fifo) == FIFO_FULL)
			{
				printf("yes\n");
			}
			else
			{
				printf("NO\n");
			}
			break;
		case 4:
			if(FIFO_is_empty(&UART_fifo) == FIFO_EMPTY)
						{
							printf("yes\n");
						}
						else
						{
							printf("NO\n");
						}

			break;
		case 5:
			FIFO_display(&UART_fifo);
			break;
		}
	}
	return EXIT_SUCCESS;
}
