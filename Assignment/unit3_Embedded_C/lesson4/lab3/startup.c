#include "stdio.h"
#include "platform_types.h"

extern int main(void);

static uint32 Stack_top[256];

extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

void Reset_Handler(void);

void Default_Handler()
{
    Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));

void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));


void (*const g_p_fun_vectors[])() __attribute__((section(".vectors")))=
{
    (void (*const)()) ( (uint32)Stack_top + sizeof(Stack_top)),
    &Reset_Handler,
    &H_Fault_Handler,
    &MM_Fault_Handler
};

void Reset_Handler(void)
{
    uint32 data_size = (uint8 *)&_E_data - (uint8 *)&_S_data;
    uint8 *P_src = (uint8 *)&_E_text;
    uint8 *P_dst = (uint8 *)&_S_data;

    while (data_size--)
    {
        *(P_dst++) = *(P_src++);
    }

    uint32 bss_size = (uint8 *)&_E_bss - (uint8 *)&_S_bss;
    P_dst = (uint8 *)&_S_bss;

    while (bss_size--)
    {
        *(P_dst++) = 0;
    }

    main();
}
