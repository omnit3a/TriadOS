AS = nasm
AFLAGS = -f elf32
OUTPUT = boot.o
INPUT = asm/boot.asm
CPPINPUT = cpp/*.c
QFLAGS = -fda
CC = ./i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-g++
all:
	$(AS) $(AFLAGS) $(INPUT) -o $(OUTPUT)
	$(CC) -m32 $(CPPINPUT) boot.o -o kernel.bin -nostdlib -ffreestanding -std=c++11 -mno-red-zone -fno-exceptions -nostdlib -fno-rtti -Wall -Wextra -T linker.ld -w
	qemu-system-x86_64 $(QFLAGS) kernel.bin
