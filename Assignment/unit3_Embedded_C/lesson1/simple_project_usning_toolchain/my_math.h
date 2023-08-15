#ifndef MY_MATH_H
#define MY_MATH_H

#include "platform_types.h"


#define PI 3.14159265359

extern float32  sum(float32,float32);
extern float32  sub(float32,float32);
extern float32  mul(float32,float32);
extern float32  div(float32,float32);
extern sint32   mod(float32,float32);
extern float32  powr(float32,float32);
extern float32  squr(float32);
extern float32  c_area(float32);
extern uint32   facto(float32);
extern uint8    is_integer(float32);

#endif /*MY_MATH_H*/