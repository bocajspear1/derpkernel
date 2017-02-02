.PHONY: all
all: start drivers info kernel link

.PHONY: start
start:
	nasm -f elf32 dkernel_start.asm -o obj/kasm.o

.PHONY: kernel
kernel: drivers
	@echo "\nCompiling kernel\n"
	nasm -f elf32 idt/load_idt.asm -o obj/load_idt.o 
	gcc -m32 -c dkernel.c -o obj/kc.o 
	gcc -m32 -c idt/idt.c -o obj/idt.o -fno-stack-protector
	nasm -f elf32 mem/load_gdt.asm -o obj/load_gdt.o 
	gcc -m32 -c mem/gdt.c -o obj/gdt.o 

.PHONY: drivers
drivers:
	@echo "\nCompiling drivers\n"
	nasm -f elf32 drivers/io.asm -o obj/io.o 
	gcc -m32 -c drivers/screen/simple_screen.c -o obj/simple_screen.o
	nasm -f elf32 drivers/keyboard/keyboard_handler.asm -o obj/keyboard_handler.o 
	gcc -m32 -c drivers/keyboard/keyboard_main.c -o obj/keyboard_main.o

.PHONY: info
info:
	@echo "\nCompiling info\n"
	nasm -f elf32 info/reg.asm -o obj/reg.o 


.PHONY: link
link:
	@echo "\nLinking\n"
	ld -m elf_i386 -T dklink.ld -o kernel obj/*.o -Map kernel.map

.PHONY: clean
clean:
	rm kernel
	rm obj/*.o

.PHONY: run
run:
	qemu-system-i386 -kernel kernel

.PHONY: debugrun
debugrun:
	qemu-system-i386 -kernel kernel -d cpu_reset