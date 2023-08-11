#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void revers(char *num,int len);

void main ()
{
	char num[20] ;
	scanf("%s",num);
	revers(num,strlen(num));
	printf("%s",num);
}


void revers(char *num,int len)
{
	int i ;
	for(i =0 ; i < len/2 ; i++)
	{
		num[i] ^= num[len-i-1];
		num[len-i-1] ^= num[i];
		num[i] ^= num[len-i-1];
	}
}