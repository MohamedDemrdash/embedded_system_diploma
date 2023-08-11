#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	float num;
	printf("enter a number :\n");
	scanf("%f",&num);
	if(num > 0)
	{
		printf("%f is positive",num);
	}
	else if(num < 0)
	{
		printf("%f  is negative",num);		
	}
	else
	{
		printf("0 is netural");
	}
}


