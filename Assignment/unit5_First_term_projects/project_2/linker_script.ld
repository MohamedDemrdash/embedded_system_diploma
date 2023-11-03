/*
 * File Name  : linker_script.ld
 * File Type  : Linker File.
 * Layer Name : 
 * Created on : Nov 2, 2023.
 * Author     : Mohamed Hussein Demrdash.
 * Description: This is linker file of STM32F103C6.
 * 
 */


MEMORY
{
    flash(RX): ORIGIN = 0x08000000, LENGTH = 128K
    sram(RWX): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .vectors :
    {
        startup.o(.rodata*)
    }>flash
    .text :
    {
        *(.text)
        *(.rodata)
        _E_text = .;
    }>flash

    .data :
    {
        _S_data = .;
        *(.data)
        _E_data = .;
    }>sram AT> flash

    .bss :
    {
        _S_bss = .;
        *(.bss)
        . = ALIGN(4);
        _E_bss = .;
 
    . =  ALIGN(4);
    . = . + 0X1000 ;
     _stack_top = .;

    }>sram
}