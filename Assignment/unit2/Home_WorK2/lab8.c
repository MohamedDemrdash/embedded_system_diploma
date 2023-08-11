#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char is_integer(float num);

void main ()
{
	float num1 ,num2;
	char op;
	while(1)
	{
		scanf("%f",&num1);
		scanf("%c",&op);
		while(op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
		{
			scanf("%c",&op);
		}
		scanf("%f",&num2);
		switch(op)
		{
		case '+' :
			printf("%f %c %f = %f",num1,op,num2,num1+num2);
			break;
		case '-' :
			printf("%f %c %f = %f",num1,op,num2,num1-num2);
			break;
		case '*' :
			printf("%f %c %f = %f",num1,op,num2,num1*num2);
			break;
		case '/' :
			if(num2 != 0)
			{
				printf("%f %c %f = %f",num1,op,num2,num1/num2);
			}
			else
			{
				printf("Error!!! Can't divide by Zero");
			}
			break;
		case '%' :
			if(num2 != 0)
			{
				if(is_integer(num1) && is_integer(num2))
				{
					printf("%f %c %f = %d",num1,op,num2,(int)num1%(int)num2);
				}
				else
				{
					printf("Error!!! Can't use % with float Numbers");
				}
			}
			else
			{
				printf("Error!!! Can't divide by Zero");
			}
			break;

		}
		printf("\n");
	}
}
char is_integer(float num)
{
	int test = (int)num;
	return (char)(test/num);
}

