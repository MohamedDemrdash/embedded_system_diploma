/*This file should not be included in the project because
 *it is a library. It will be included by the linker
 *at linking stage.
 */
//#include "stdio.h"
#include "my_math.h"
#include "platform_types.h"

extern float32 sum(float32 num1, float32 num2)
{
    return num1 + num2;
}

extern float32 sub(float32 num1, float32 num2)
{
    return num1 - num2;
}

extern float32 mul(float32 num1, float32 num2)
{
    return num1 * num2;
}

extern float32 div(float32 num1, float32 num2)
{
    float32 resulte = 0;
    if (num2 != 0)
    {
        resulte = num1 / num2;
    }
    else
    {
        
    }
    return resulte;
}

extern sint32 mod(float32 num1, float32 num2)
{
    sint32 resulte = 0;
    if (num2 != 0)
    {
        if (is_integer(num1) && is_integer(num2))
        {
            resulte = (sint32)num1 % (sint32)num2;
        }
        else
        {

        }
    }
    else
    {

    }
    return resulte;
}

extern float32 powr(float32 num1, float32 num2)
{
    float32 resulte = 1;
    while (num2--)
    {
        resulte *= num1;
    }

    return resulte;
}

extern float32 squr(float32 num)
{
    float32 root = 1;
    sint32 i = 100;
    while (i--)
    {
        root = root - (root * root - num) / (2 * root);
    }
    return root;
}

extern float32 c_area(float32 R)
{
    return PI * powr(R, 2);
}

extern uint32 facto(float32 num)
{
    uint32 resulte = 1;
    if (num >= 0)
    {
        if (is_integer(num))
        {
            uint32 i;
            for (i = 1; i <= num; i++)
            {
                resulte *= i;
            }
        }
        else
        {

        }
    }
    else
    {
        
    }
    return resulte;
}

extern uint8 is_integer(float32 num)
{
    sint32 test = (sint32)num;
    return (uint8)(test / num);
}