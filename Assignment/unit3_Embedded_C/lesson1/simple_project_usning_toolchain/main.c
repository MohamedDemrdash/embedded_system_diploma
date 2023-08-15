#include "stdio.h"
#include "my_math.h"
#include "platform_types.h"

void main()
{
    float32 num1 , num2;
    printf("Enter two numbers : \n");
    scanf("%f",&num1);
    scanf("%f",&num2);
    printf("%f + %f = %f\n",num1,num2,sum(num1,num2));
    printf("%f %% %f = %d\n",num1,num2,mod(num1,num2));
    printf("%f^%f = %f\n",num1,num2,powr(num1,num2));
    printf("%f! = %d\n",num1,facto(num1));
    printf("%f! = %d\n",num2,facto(num2));
}