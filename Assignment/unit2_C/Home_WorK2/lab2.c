/*
 ============================================================================
 Name        : vowel_constant.c
 Author      : Mohamed Demrdash
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char x;
	printf("Enter the letter you want to check : \n");
	scanf("%c",&x);
	switch(x)
	{
		case 'a':
		case 'A':
		case 'o':
		case 'O':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'u':
		case 'U':
			printf("%c is vowel letter \n",x);
			break;
		default:
			printf("%c is constant letter \n",x);
	}
	return 1;
}
