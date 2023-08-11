#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define SIZE 7

void unique(int *num);

void main ()
{
	int num[SIZE];
	int i ;
	for(i =0 ;i < SIZE ;i++)
	{
		scanf("%d",&num[i]);
	}
	
	unique(num);
}


void unique(int *num)
{
	int i = 0, flag;
	char test[100] = {0}; //you can enter any number in the rang of 0  to 99
	for( ; i<SIZE;i++)
	{
		test[num[i]]++;
		if(test[num[i]] ==  1)
		{
			flag = i;
		}
		
	}
	printf("%d",num[flag]);
}