#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	char c;
	printf("enter a character : ");
	fflush(stdin);
	scanf("%c",&c);
	if((c >= 'A') && (c <= 'Z') ||  (c >= 'a') && (c <= 'z'))
	{
		printf("%c is an alphabet",c);
	}
	else
	{
		printf("%c is not an alphabet",c);
	}
}


