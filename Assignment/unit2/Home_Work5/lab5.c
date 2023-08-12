#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define AREA(R) (M_PI*R*R)

void main ()
{
	short r =0 ;
	printf("Enter the radius : ");
	scanf("%d",&r);
	printf("Area = %f",AREA(r)); 
}