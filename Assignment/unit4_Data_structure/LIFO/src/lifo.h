/*
 * lifo.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Demrdash
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "platform_types.h"

#define element_type uint16

typedef struct
{
	element_type* head;
	element_type* base;
	uint16  count;
	uint16  length;
}LIFO_buffer;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_state;

LIFO_state LIFO_init     (LIFO_buffer* lifo_buf,element_type* arr,uint16 length);
LIFO_state LIFO_add      (LIFO_buffer* lifo_buf,element_type item);
LIFO_state LIFO_get      (LIFO_buffer* lifo_buf,element_type* item);
LIFO_state LIFO_is_full  (LIFO_buffer* lifo_buf);
LIFO_state LIFO_is_empty (LIFO_buffer* lifo_buf);
LIFO_state LIFO_display   (LIFO_buffer* lifo_buf);


#endif /* LIFO_H_ */
