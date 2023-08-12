#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct STUDENT
{
	short marks;
	char name[21];
	char roll;
};


void main ()
{
	struct STUDENT student[10];
	char i;
	for (i = 0; i < 3; i++)
	{
		printf("Enter information of student no. %d:- \n",i+1);
		printf("Enter name        : ");
		fflush(stdin);
		gets(student[i].name);
		printf("Enter roll number : ");
		scanf("%d",&student[i].roll);
		printf("Enter marks       : ");
		scanf("%hd",&student[i].marks);

	}
	
	for (i = 0; i < 3; i++)
	{
		printf("Displaying Informaton of student no. %d:- \n",i+1);
		printf("Name  : %s\n",student[i].name);
		printf("Roll  : %d\n",student[i].roll);
		printf("Marks : %hd\n",student[i].marks);
		printf("\n");
	}
}