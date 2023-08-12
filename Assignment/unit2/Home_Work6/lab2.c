#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	char ch = 'A',*const p = &ch ;
	while (*p <= 'Z')
	{
		printf("%c\t",(*p)++);
	}
	
	
}