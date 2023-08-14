#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct DISTANCE
{
	float feet;
	float inch;
};


void main ()
{
	struct DISTANCE d1,d2,d3;
	printf("Enter information of 1st Distance :-\n");
	printf("Enter feet : ");
	scanf("%f",&d1.feet);
	printf("Enter inch : ");
	scanf("%f",&d1.inch);
	if(d1.inch > 12)
	{
		d1.feet += (int)d1.inch/12;
		d1.inch -= ((int)d1.inch/12)*12;
	}
	printf("Enter information of 2nd Distance :-\n");
	printf("Enter feet : ");
	scanf("%f",&d2.feet);
	printf("Enter inch : ");
	scanf("%f",&d2.inch);
	if(d2.inch > 12)
	{
		d2.feet += (int)d2.inch/12;
		d2.inch -= ((int)d2.inch/12)*12;
	}

	d3.feet = d1.feet + d2.feet;
	d3.inch = d1.inch + d2.inch;
	if(d3.inch > 12)
	{
		d3.feet += (int)d3.inch/12;
		d3.inch -= ((int)d3.inch/12)*12;
	}
	printf("%0.2f'%0.2f\"",d3.feet,d3.inch);
}