/*
 * File Name  : startup.c
 * File Type  : Source File.
 * Layer Name : 
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This is the startup code for STM32F103C6.
 * 
 */

#include "platform_types.h"


extern int main(void); //Declare the main function.

extern uint32 _stack_top; //The last location of the stack.
extern uint32 _E_text;    //The end of text section.
extern uint32 _S_data;    //The start of data section.
extern uint32 _E_data;    //The end of data section.
extern uint32 _S_bss;     //The start of bss section.
extern uint32 _E_bss;     //The end of bss section.


//prototypes of the interupt handlers
void Reset_Handler(void);

void Default_Handler()
{
    Reset_Handler();
}

void NMI_Handler        (void)__attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler    (void)__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler   (void)__attribute__((weak,alias("Default_Handler")));


//initialzie the IVT
const uint32 vectors[] =
{
    (uint32) &_stack_top, //Set the stack pointer
    (uint32) &Reset_Handler,
    (uint32) &H_Fault_Handler,
    (uint32) &MM_Fault_Handler,
};


void Reset_Handler(void)
{
    //copy the data section from ROM to RAM.
    uint32 data_size = (uint8 *)&_E_data - (uint8 *)&_S_data;
    uint8 * P_src = (uint8 *)&_E_text;
    uint8 * P_dst = (uint8 *)&_S_data;

    while (data_size--)
    {
        *(P_dst++) = *(P_src++);
    }

    //Reserve a section for bss at RAM and initialize it with Zeros.
    uint32 bss_size = (uint8 *)&_E_bss - (uint8 *)&_S_bss;
    P_dst = (uint8 *)&_S_bss;
    
    while (bss_size--)
    {
        *(P_dst++) = 0;
    }

    main(); //Call the main and start the excuation of the programe.
}
