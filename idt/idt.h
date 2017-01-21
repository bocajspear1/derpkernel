/*

This defines the IDT, the Interrupt Descriptor Table.

See here:
http://wiki.osdev.org/IDT
https://en.wikipedia.org/wiki/Interrupt_descriptor_table

This allows us to use interrupts to get cool things
like keyboard input

*/
#ifndef IDT_H
#define IDT_H

#include "inttypes.h"

#include "pic.h"

#define IDT_SIZE 256

struct IDT_ENTRY{
	uint16_t offset_lowerbits;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_higherbits;
};

struct IDT_ENTRY IDT[IDT_SIZE];

void add_idt_entry(uint8_t irq, uint32_t handler, uint16_t selector, uint8_t type_attr);
void idt_init(void);

#endif //IDT_H