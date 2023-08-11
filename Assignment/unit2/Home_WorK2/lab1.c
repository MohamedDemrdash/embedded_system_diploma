/*
 ============================================================================
 Name        : even_odd.c
 Author      : Mohamed Demrdash
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x;
	printf("Enter the number you want to check : \n");
	scanf("%d",&x);
	if(x%2 == 0)
	{
		printf("%d is even",x);
	}
	else
	{
		printf("%d is odd",x);
	}
	return 1;
}
