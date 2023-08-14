#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"



void main ()
{

	int row,col,r,c;
	printf("Enter row and column of matrix : ");
	scanf("%d",&row);
	scanf("%d",&col);
	float *arr = (float *)malloc(sizeof(float)*row*col);
	printf("Enter the elements of the matrix\n");
	for(r = 0 ; r < row; ++r)
	{
		
		for(c =0 ; c < col ; c++)
		{
			printf("Enter a%d%d : ",r+1,c+1);
			scanf("%f",((arr + r*col)+c));
		}
	}

	printf("Entered matrix\n");
	for(r = 0 ; r < row; ++r)
	{
		for(c =0 ; c < col ; c++)
		{
			printf("%0.2f\t",(arr+r*col)[c]);
		}
		printf("\n");
	}

	printf("Transpose of Matrix\n");
	for(c = 0 ; c < col; ++c)
	{
		for(r =0 ; r < row ; r++)
		{
			printf("%0.2f\t",(arr+r*col)[c]);
		}
		printf("\n");
	}
	free(arr);
}


