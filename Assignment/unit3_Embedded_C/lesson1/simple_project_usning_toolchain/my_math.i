# 0 ".\\my_math.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 ".\\my_math.c"





# 1 ".\\my_math.h" 1



# 1 ".\\platform_types.h" 1
# 39 ".\\platform_types.h"
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;
typedef signed long sint8_least;
typedef signed long sint16_least;
typedef signed long sint32_least;
typedef float float32;
typedef double float64;
# 5 ".\\my_math.h" 2




extern float32 sum(float32,float32);
extern float32 sub(float32,float32);
extern float32 mul(float32,float32);
extern float32 div(float32,float32);
extern sint32 mod(float32,float32);
extern float32 powr(float32,float32);
extern float32 squr(float32);
extern float32 c_area(float32);
extern uint32 facto(float32);
extern uint8 is_integer(float32);
# 7 ".\\my_math.c" 2


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
    return 3.14159265359 * powr(R, 2);
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
