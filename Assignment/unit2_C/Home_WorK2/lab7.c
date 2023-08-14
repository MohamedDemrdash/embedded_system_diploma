#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	int num ,fact = 1;
	printf("enter an integer : ");
	scanf("%d",&num);
	if(num >= 0)
	{
		int i ;
		for(i =1;i <= num;i++)
		{
			fact *= i;
		}
		printf("Factorial = %d",fact);		
	}
	else
	{
		printf("Error!! Factorial of negative number desnit exist");
	}
}


