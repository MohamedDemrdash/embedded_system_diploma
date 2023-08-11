#include "stdio.h"
#include "stdlib.h"
#include "string.h"

float squr(int num);

void main ()
{
	int num =0 ;
	scanf("%d",&num);
	printf("%f\n",squr(num));
}


float squr(int num)
{
	float root = 1;
	int i = 100;
	while(i--)
	{
		root = root - (root*root - num)/(2*root);
	}
	return root;
}