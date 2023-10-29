/*
 * fifo.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mohamed Demrdash
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "platform_types.h"


#define element_type uint8


typedef struct
{
	element_type* base;
	element_type* head;
	element_type* tail;
	uint16 length;
	uint16 count;
}FIFO_buffer;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_state;

#define FIFO_INIT(FIFO_BUF,SIZE)	element_type FIFO_BUF##_base_arr[SIZE];\
									FIFO_buffer FIFO_BUF##_fifo;\
									FIFO_init(&FIFO_BUF##_fifo,FIFO_BUF##_base_arr,SIZE)


FIFO_state FIFO_init     (FIFO_buffer* fifo_buf,element_type* arr,uint16 length);
FIFO_state FIFO_enqueue  (FIFO_buffer* fifo_buf,element_type  item);
FIFO_state FIFO_dequeue  (FIFO_buffer* fifo_buf,element_type* item);
FIFO_state FIFO_is_full  (FIFO_buffer* fifo_buf);
FIFO_state FIFO_is_empty (FIFO_buffer* fifo_buf);
FIFO_state FIFO_display  (FIFO_buffer* fifo_buf);


#endif /* FIFO_H_ */
