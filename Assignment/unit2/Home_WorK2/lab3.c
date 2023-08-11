#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	float num[3];
	printf("enter three numbers :\n");
	scanf("%f",&num[0]);
	scanf("%f",&num[1]);
	scanf("%f",&num[2]);
	if(num[0] > num [1])
	{
		if(num[0] > num[2])
		{
			printf("largest number = %f",num[0]);
		}
		else
		{
			printf("largest number = %f",num[2]);
		}
	}
	else
	{
		if(num[1] > num[2])
		{
			printf("largest number = %f",num[1]);
		}
		else
		{
			printf("largest number = %f",num[2]);
		}		
	}
}


