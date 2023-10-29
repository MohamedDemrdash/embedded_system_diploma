/*
 * lifo.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Demrdash
 */

#include  "lifo.h"
#include  "platform_types.h"
#include  "stdio.h"


LIFO_state LIFO_init(LIFO_buffer* lifo_buf,element_type* arr,uint16 length)
{
	LIFO_state state;

	if(!arr)
	{
		state = LIFO_NULL;
	}
	else
	{
		lifo_buf->base = arr;
		lifo_buf->head = arr;
		lifo_buf->length = length;
		lifo_buf->count = 0;
		state = LIFO_NO_ERROR;
	}

	return state;
}

LIFO_state LIFO_add(LIFO_buffer* lifo_buf,element_type item)
{
	LIFO_state state;
	if((state = LIFO_is_full(lifo_buf)) == LIFO_NO_ERROR)
	{
		*(lifo_buf->head ++) = item;
		(lifo_buf->count)++;
		state = LIFO_NO_ERROR;
	}
	else
	{

	}
	return state;
}

LIFO_state LIFO_get(LIFO_buffer* lifo_buf,element_type* item)
{
	LIFO_state state;
		if((state = LIFO_is_empty(lifo_buf)) == LIFO_NO_ERROR)
		{
			*item = *(--lifo_buf->head);
			(lifo_buf->count)--;
		}
		else
		{

		}

		return state;

}

LIFO_state LIFO_is_full  (LIFO_buffer* lifo_buf)
{
	LIFO_state state;

	if(lifo_buf->base || lifo_buf->head)
	{
		if(lifo_buf->count >= lifo_buf->length)
		{
			state = LIFO_FULL;
		}
		else
		{
			state = LIFO_NO_ERROR;
		}

	}
	else
	{
		state = LIFO_NULL;
	}

	return state;
}
LIFO_state LIFO_is_empty (LIFO_buffer* lifo_buf)
{
	LIFO_state state;

		if(lifo_buf->base || lifo_buf->head)
		{
			if(lifo_buf->count <= 0)
			{
				state = LIFO_EMPTY;
			}
			else
			{
				state = LIFO_NO_ERROR;
			}
		}
		else
		{
			state = LIFO_NULL;
		}

		return state;
}

LIFO_state LIFO_display   (LIFO_buffer* lifo_buf)
{
	LIFO_state state;
	if(lifo_buf->base || lifo_buf->head)
	{
		uint16 count = 0;
		for(count = 0;count < lifo_buf->count;count++)
		{
			printf("%d\n",*(lifo_buf->base+count));
		}
	}
	else
	{
		state = LIFO_NULL;
	}
	return state;
}
