#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void num_ones(int num);

void main ()
{
	int num = 0 ;
	scanf("%d",&num);
	num_ones(num);
}

void num_ones(int num)
{
	int one = 0 ;
	while(num)
	{
		if(num &1 )
		{
			one++;
		}
		else
		{
			
		}
		num >>=1;
	}
	printf("%d",one);
}