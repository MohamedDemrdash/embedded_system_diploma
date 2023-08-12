#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	char str[20] ;
	char *ptr = str;

	printf("Enter string  : ");
	scanf("%s",str);
	printf("Input string  : ");
	//printf("%s",str);
	while ((*ptr))
	{
		printf("%c",*(ptr++));
	}
	printf("\nRevers string : ");
	do
	{
		printf("%c",*(--ptr));
		*(ptr+1) = 0;
	} while (strlen(str));
	
	
	
}