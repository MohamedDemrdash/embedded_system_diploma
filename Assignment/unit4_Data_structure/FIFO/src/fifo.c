/*
 * fifo.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mohamed Demrdash
 */
#include "fifo.h"
#include "platform_types.h"
#include "stdio.h"

FIFO_state FIFO_init     (FIFO_buffer* fifo_buf,element_type* base_arr,uint16 length)
{
	FIFO_state state;

		if(!base_arr)
		{
			state = FIFO_NULL;
		}
		else
		{
			fifo_buf->base = base_arr;
			fifo_buf->head = base_arr;
			fifo_buf->tail = base_arr;
			fifo_buf->length = length;
			fifo_buf->count = 0;
			state = FIFO_NO_ERROR;
		}

		return state;


}

FIFO_state FIFO_enqueue  (FIFO_buffer* fifo_buf,element_type  item)
{
	FIFO_state state;
	if((state = FIFO_is_full(fifo_buf)) == FIFO_NO_ERROR)
	{
		if(fifo_buf->tail == fifo_buf->base +fifo_buf->length)
		{
			fifo_buf->tail = fifo_buf->base;
		}
		*(fifo_buf->tail ++) = item;
		(fifo_buf->count)++;
		state = FIFO_NO_ERROR;
	}
	else
	{

	}
	return state;
}

FIFO_state FIFO_dequeue  (FIFO_buffer* fifo_buf,element_type* item)
{
	FIFO_state state;
	if((state = FIFO_is_empty(fifo_buf)) == FIFO_NO_ERROR)
	{
		if(fifo_buf->head == fifo_buf->base + fifo_buf->length)
		{
			fifo_buf->head = fifo_buf->base;
		}
		*item = *(fifo_buf->head++);
		(fifo_buf->count)--;
	}
	else
	{

	}

	return state;
}

FIFO_state FIFO_is_full  (FIFO_buffer* fifo_buf)
{
	FIFO_state state;

	if(fifo_buf->base && fifo_buf->head && fifo_buf->tail)
	{
		if(fifo_buf->count >= fifo_buf->length)
		{
			state = FIFO_FULL;
		}
		else
		{
			state = FIFO_NO_ERROR;
		}

	}
	else
	{
		state = FIFO_NULL;
	}

	return state;

}

FIFO_state FIFO_is_empty (FIFO_buffer* fifo_buf)
{
	FIFO_state state;

	if(fifo_buf->base && fifo_buf->head && fifo_buf->tail)
	{
		if(fifo_buf->count <= 0)
		{
			state = FIFO_EMPTY;
		}
		else
		{
			state = FIFO_NO_ERROR;
		}

	}
	else
	{
		state = FIFO_NULL;
	}

	return state;

}
FIFO_state FIFO_display  (FIFO_buffer* fifo_buf)
{
	FIFO_state state;
	if(fifo_buf->base && fifo_buf->head && fifo_buf->tail)
	{
		sint16 count = 0 ,index =0;
		for(count = 0;count < fifo_buf->count;count++ ,index++)
		{
			if(fifo_buf->head + index == fifo_buf->base +fifo_buf->length)
			{
				index = (sint16)(index - fifo_buf->length);
			}
			printf("%d\n",*(fifo_buf->head+index));

		}
	}
	else
	{
		state = FIFO_NULL;
	}
	return state;
}
