#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void prim(int num1,int num2);

void main ()
{
	int num1 =0,num2=0 ;
	scanf("%d",&num1);
	scanf("%d",&num2);
	prim(num1,num2);
}


void prim(int num1,int num2)
{
	int i = num1;
	int flag = 0;
	for( ; i <=num2 ; i++)
	{
		
		if((i%2 == 0) && (i != 2) || (i == 1))
		{
			continue;
		}
		else
		{
			int j;
			for(j = 3 ; j<= sqrt(i) ; j=j+2)
			{
				if(i%j == 0)
				{
					flag ++;
					break;
				}
			}
			if(flag == 0)
			{
				printf("%d ",i);
			}
			else
			{
				flag =0 ;
			}
		}
	}
}