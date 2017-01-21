#include "idt.h"

extern void wportb(uint16_t, uint8_t);
extern void load_idt(uint32_t *);

void add_idt_entry(uint8_t irq, uint32_t handler, uint16_t selector, uint8_t type_attr) {
    uint8_t int_num = PIC_OFFSET + irq;
    IDT[int_num].offset_lowerbits = handler & 0xffff;
	IDT[int_num].selector = selector; 
	IDT[int_num].zero = 0;
	IDT[int_num].type_attr = type_attr;
	IDT[int_num].offset_higherbits = (handler & 0xffff0000) >> 16;
}

void idt_init(void) {

    uint32_t idt_address;
	uint32_t idt_ptr[2];

    // Initialize PICs
    wportb(PIC1_COM , PIC_INIT);
    wportb(PIC2_COM , PIC_INIT);

    // ICW2 - Offset
    wportb(PIC1_DAT , PIC_OFFSET);
	wportb(PIC2_DAT , PIC_OFFSET+8);

    // ICW3 - Setup cascading
    wportb(PIC1_DAT , 0x0);
	wportb(PIC2_DAT , 0x0);

    // ICW4 - Environment info
    wportb(PIC1_DAT , ICW4_8086);
	wportb(PIC2_DAT , ICW4_8086);

    /* mask interrupts */
	wportb(PIC1_DAT , 0xff);
	wportb(PIC2_DAT , 0xff);

    // Setup IDT description structure
    idt_address = (unsigned long)IDT;
	idt_ptr[0] = (sizeof(struct IDT_ENTRY) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16;

    load_idt(idt_ptr);
}