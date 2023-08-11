#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define ROW 2
#define COL 2

void main ()
{
	float a[ROW][COL],b[ROW][COL];
	char row,col;
	
	printf("Enter the elements of 1st matrix\n");
	for(row = 0 ; row < ROW; ++row)
	{
		for(col =0 ; col < COL ; col++)
		{
			printf("Enter a%d%d : ",row+1,col+1);
			scanf("%f",&a[row][col]);
		}
	}
	
	printf("Enter the elements of 2nd matrix\n");
	for(row = 0 ; row < ROW; ++row)
	{
		for(col =0 ; col < COL ; col++)
		{
			printf("Enter b%d%d : ",row+1,col+1);
			scanf("%f",&b[row][col]);
		}
	}

	printf("Sum of Matrix\n");
	for(row = 0 ; row < ROW; ++row)
	{
		for(col =0 ; col < COL ; col++)
		{
			printf("%0.2f\t",a[row][col]+b[row][col]);
		}
		printf("\n");
	}

}


