#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int power(int num,int p);

void main ()
{
	int num,p;
	printf("Enter a base : ");
	scanf("%d",&num);
	printf("Enter power : ");
	scanf("%d",&p);
	printf("%d^%d = %d",num,p,power(num,p));
	power(num,p);	
}

int power(int num,int p)
{
	int result = 1;
	if(p > 0)
	{
		result = num*power(num,p-1);
	}
	else
	{
		
	}
	return result;
}
