ENTRY(reset)

MEMORY
{
    MEM(rwx) : o = 0x00000000, l = 64M
}

SECTIONS
{
    . = 0X00010000;
    .startup . :
    {
        startup.o(.text)
    }>MEM
    .text :
    {
        *(.text)
    }>MEM
    .data :
    {
        *(.data)
    }
    .bss :
    {
        *(.bss) *(.rodata)
    }

    . = . + 0x00001000;
    stack_top = .;
}