#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{
	int num = 29,*p ;
	printf("Address of num : %p\n",&num);
	printf("Value of num : %d\n",num);

	p = &num;

	printf("Address of pointer : %p\n",p);
	printf("Content of pointer : %d\n",*p);

	num = 34; 

	printf("Address of pointer : %p\n",p);
	printf("Content of pointer : %d\n",*p);
	
	*p = 7;

	printf("Address of num : %p\n",&num);
	printf("Value of num : %d\n",num);
}