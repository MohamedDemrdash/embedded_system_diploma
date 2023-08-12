#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct COMPLEX
{
	float real;
	float imag;
};


void main ()
{
	struct COMPLEX c1,c2;
	printf("Enter 1st Number :-\n");
	printf("Enter real part : ");
	scanf("%f",&c1.real);
	printf("Enter imaginary part : ");
	scanf("%f",&c1.imag);
	
	printf("Enter 2nd Number :-\n");
	printf("Enter real part : ");
	scanf("%f",&c2.real);
	printf("Enter imaginary part : ");
	scanf("%f",&c2.imag);
	
	printf("SUM = %0.2f + %0.2fi",c1.real+c2.real,c1.imag+c2.imag);
}