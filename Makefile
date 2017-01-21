.PHONY: all
all: start kernel drivers link

.PHONY: start
start:
	nasm -f elf32 dkernel_start.asm -o kasm.o

.PHONY: kernel
kernel:
	gcc -m32 -c dkernel.c -o kc.o

.PHONY: drivers
drivers:
	gcc -m32 -c drivers/screen/simple_screen.c -o simple_screen.o

.PHONY: link
link:
	ld -m elf_i386 -T dklink.ld -o kernel kasm.o kc.o simple_screen.o