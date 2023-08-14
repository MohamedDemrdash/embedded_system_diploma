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
	struct STUDENT s1;
	printf("Enter information of student :- \n");
	printf("Enter name : ");
	gets(s1.name);
	printf("Enter roll number : ");
	scanf("%d",&s1.roll);
	printf("Enter marks : ");
	scanf("%hd",&s1.marks);

	printf("Displaying Informaton\n");
	printf("Name : %s\n",s1.name);
	printf("Roll : %d\n",s1.roll);
	printf("Marks : %hd\n",s1.marks);
}