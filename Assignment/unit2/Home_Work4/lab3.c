#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void revers(char *str);

void main ()
{
	char str[50];
	printf("Enter a sentece : ");
	gets(str);
	revers(str);	
}

void revers(char *str)
{
	if(*str != 0)
	{
		revers(str+1);
		printf("%c",*str);
	}
	else
	{
		
	}
}
