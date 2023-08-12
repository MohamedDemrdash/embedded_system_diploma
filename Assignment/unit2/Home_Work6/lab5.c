#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct EMPLOYEE
{
	short id;
	char name[20];
};

void main()
{
	struct EMPLOYEE employee[10];
	struct EMPLOYEE* (*ptr)[10]; 
	char i = 0, c = 0;
	for ( i = 0; i < 10; i++)
	{
		*(*ptr+i) = employee+i;
	}
	i = 0;
	while (i < 10 && c != 'N' && c != 'n')
	{
		printf("Do you want to enter a new employee ? (Y/N) : ");
		fflush(stdin);
		scanf("%c",&c);
		if (c == 'y' || c == 'Y')
		{

			printf("Enter information of employee no. %d:- \n", i + 1);
			printf("Enter name        : ");
			fflush(stdin);
			gets((*(*ptr+i))->name);
			printf("Enter ID          : ");
			scanf("%hd", &(*(*ptr+i))->id);
			printf("\n\n");

			printf("Displaying Informaton of employee no. %d:- \n", i + 1);
			printf("Name  : %s\n", (*(*ptr+i))->name);
			printf("ID    : %hd\n", (*(*ptr+i))->id);
			printf("\n\n");
			i++;
		}
	}
}