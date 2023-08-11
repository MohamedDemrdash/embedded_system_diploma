#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int sum(int num1,int num2);

void main ()
{
	int num1 = 0,num2=0 ;
	scanf("%d",&num1);
	scanf("%d",&num2);
	printf("%d",sum(num1,num2));
}


int sum(int num1,int num2)
{
	int sum = 0;
	if(num1 > num2)
	{
		num1 ^= num2;
		num2 ^= num1;
		num1 ^= num2;
	}
	else
	{
		
	}
	sum = num2*(num2+1)/2 - num1*(num1+1)/2 +num1;
	return sum;
}