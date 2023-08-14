#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define SIZE 50

void main ()
{

	char str[SIZE];
	printf("Enter a string : ");
	gets(str);
	char c;
	printf("Enter a chaecter to find frequency : ");
	scanf("%c",&c);
	char count = 0 ,*ptr = str;
	while(*ptr != 0)
	{
		if((*ptr == c) || (*ptr == (c^0x20)))
		{
			count++;
		}
		else
		{
			
		}
		ptr++;
	}
	if(count == 0)
	{
		printf("Sorry! can not find your letter");
	}
	else
	{
		printf("Frequency of %c = %d",c,count);		
	}
}


