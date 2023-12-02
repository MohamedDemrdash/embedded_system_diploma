 ##################
 # File Name  : Makefile
 # File Type  : Make File.
 # Layer Name : 
 # Created on : Nov 2, 2023.
 # Author     : Mohamed Hussein Demrdash.
 ##################
 
CC=arm-none-eabi
CFLAGS=-gdwarf-2
CORE=-mcpu=cortex-m3
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
INCS= I .
LIBS=
PROJ=Lab_1

.PHONY:all clean_all clean

all:$(PROJ).bin
	@echo "+++++Build is Done+++++"

%.o:%.s
	$(CC)-as  $(CORE) $(CFLAGS) $< -o $@

%.o:%.c
	$(CC)-gcc $(CORE) $(CFLAGS) -c $< -o $@

%.s:%.c
	$(CC)-gcc $(CORE) $(CFLAGS) -c $< -o asm/temp.o
	$(CC)-objdump -D asm/temp.o > asm/$@
	rm asm/temp.o 
#The asmebly genterated using objdump -D has more info than/
#the asmebly genterated by gcc -S


$(PROJ).elf:$(ASOBJ) $(OBJ) 
	$(CC)-ld -T *.ld $^ -o $@ -Map=map_file.map 

$(PROJ).bin:$(PROJ).elf symbols
	$(CC)-objcopy -O binary $(PROJ).elf $(PROJ).bin
	$(CC)-objcopy -O ihex   $(PROJ).elf $(PROJ).hex
	cp $(PROJ).elf $(PROJ).axf
	$(CC)-size $(PROJ).elf

obj:$(OBJ) $(ASOBJ)


asm:$(SRC:.c=.s)

rm_asm:
	rm asm/*

symbols:$(OBJ) $(ASOBJ) $(PROJ).elf
	$(CC)-nm $^ > $@.txt

clean:
	rm *.elf *.bin *.map *.txt *.hex

clean_all:
	rm *.o *.elf *.bin *.map *.txt *.hex *.axf
#shopt -s extglob
#rm -v !(*.s|*.c|*.h|*.ld|"Makefile")
#shopt -u extglob

