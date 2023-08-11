#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define SIZE 5

void revers_arr(int *num, int size);

void main ()
{
	int num[SIZE];
	int i = 0;
	for( ; i<SIZE ; i++)
	{
		scanf("%d",&num[i]);
	}
	revers_arr(num, SIZE);
}


void revers_arr(int *num, int size)
{
	while(size--)
	{
		printf("%d ",num[size]);
	}
}