MEMORY
{
    flash(RX): ORIGIN = 0x08000000, LENGTH = 512M
    sram(RWX): ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
    .vectors :
    {
        startup.o(.vectors*)
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
        app.o(.bss)
        startup.o(.bss)
        . = ALIGN(4);
        _E_bss = .;

    }>sram
}