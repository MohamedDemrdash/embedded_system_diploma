/*
 ============================================================================
 Name        : swap.c
 Author      : Mohamed Demrdash
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,y;
	printf("the first no. = \n");
	scanf("%d",&x);
	printf("the second no. = \n");
	scanf("%d",&y);
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("the first no. = %d\n",x);
	printf("the second no. = %d\n",y);
	return 1;
}
