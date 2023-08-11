  #include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define NAMES 2

void str_rev(char name[NAMES][20]);

void main ()
{
	char name[NAMES][20];
	
	str_rev(name);
}


void str_rev(char name[NAMES][20])
{
	int i = 0;
	for( ; i<NAMES;i++)
	{
		scanf("%s",name[i]);
	}
	for(i = NAMES -1 ; i >= 0; i--)
	{
		printf("%s ",name[i]);
	}
}