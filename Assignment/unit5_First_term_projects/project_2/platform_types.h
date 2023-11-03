/*
 * File Name  : platform_types.h
 * File Type  : Header File.
 * Layer Name : Services Layer (MCAL).
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This file wrote based on AtuoSAR_SWS_Platform_Types document
 * 		        R20-11 and specify the platform types for STMicroelectronics ST30
 * 		        mapped to the ANSI C types
 * 
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE_8        8
#define CPU_TYPE_16       16
#define CPU_TYPE_32       32
#define CPU_TYPE_64       64
#define MSB_FIRST         0
#define LSB_FIRST         1
#define HIGH_BYTE_FIRST   0
#define LOW_BYTE_FIRST    1


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


#define CPU_TYPE          CPU_TYPE_32
#define CPU_BIT_ORDER     LSB_FIRST
#define CPU_BYTE_ORDER    LOW_BYTE_FIRST


typedef unsigned char        boolean;
typedef signed char          sint8;
typedef unsigned char        uint8;
typedef signed short         sint16;
typedef unsigned short       uint16;
typedef signed long          sint32;
typedef signed long long     sint64;
typedef unsigned long        uint32;
typedef unsigned long long   uint64;
typedef unsigned long        uint8_least;
typedef unsigned long        uint16_least;
typedef unsigned long        uint32_least;
typedef signed long          sint8_least;
typedef signed long          sint16_least;
typedef signed long          sint32_least;
typedef float                float32;
typedef double               float64;

#endif /* PLATFORM_TYPES_H_ */











