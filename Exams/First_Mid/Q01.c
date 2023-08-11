#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void sum_dig(int num);

void main ()
{
	int num =0 ;
	scanf("%d",&num);
	sum_dig(num);
}

void sum_dig(int num)
{
	int sum =0,dig=1;
	int flag = num;
	while(flag/=10)
	{
		dig++;
	}
	while(dig--)
	{
		sum += num%10;
		num /= 10;
	}
	printf("%d",sum);
}
