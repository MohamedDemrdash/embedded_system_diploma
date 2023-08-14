#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int factorial(int num);

void main ()
{
	int num ;
	printf("Enter a positive integer : ");
	scanf("%d",&num);
	printf("Factorial of %d = %d",num,factorial(num));	
}

int factorial(int num)
{
	int fact = 1;
	if(num == 0)
	{
		
	}
	else
	{
		fact = num*factorial(num-1);	
	}
	return fact;
}
