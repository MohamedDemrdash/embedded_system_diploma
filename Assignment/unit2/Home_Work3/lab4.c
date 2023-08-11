#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define SIZE 50

void main ()
{

	int arr[SIZE];
	int i , len ,x,loc;
	printf("Enter no. of the elemnts : ");
	scanf("%d",&len);
	for(i = 0; i< len ; i++)
	{
		scanf("%d",&arr[i]);
	}
	while(len < SIZE)
	{
		printf("Enter the elemnt to be inserted : ");
		scanf("%d",&x);
		printf("Enter the location : ");
		scanf("%d",&loc);
		if(loc <= len+1)
		{
			len++;
			int temp;
			for(i = 0;i <len ;i++)
			{
				if(i == loc-1)
				{
					temp = arr[i];
					arr[i] = x;
				}
				else if(i > loc-1)
				{
					temp   ^= arr[i];
					arr[i] ^= temp;
					temp   ^= arr[i];
				}
				else
				{

				}
				printf("%d ",arr[i]);
			}
			printf("\n");
		}
		else
		{
			printf("ERROR!! YOU CAN NOT INSERT IN LOCATION EXCEED THE ARRAY LENGTH\n");
		}
	}
}


