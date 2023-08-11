#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void max_ones(int num);

void main ()
{
	int num;
	scanf("%d",&num);
	max_ones(num);
}


void max_ones(int num)
{
	int max =0,one =0;
	while(num)
	{
		if(!(num & 1))
		{
			while(((num >>= 1) & 1) && num)
			{
				one++;
			}
			if(max < one)
			{
				max = one;
				one = 0;
			}
			else
			{
				one = 0;
			}
		}
		else
		{
			num >>= 1;
		}
	}
	printf("%d",max);
}