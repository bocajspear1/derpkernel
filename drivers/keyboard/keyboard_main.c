#include "keyboard_main.h"
#include "keyboard_map.h"

extern void keyboard_handler(void);
extern unsigned char keyboard_map[128];
extern uint8_t rportb(uint16_t);
extern void wportb(uint16_t, uint8_t);

void keyboard_add(KEYBOARD_CALLBACK f) {
    callback = f;
    add_idt_entry(1, (uint32_t)keyboard_handler, 0x08, 0x8e);
}

void keyboard_init() {
    wportb(PIC1_DAT, 0xFD);
}

void keyboard_handler_main(void) {
    unsigned char status;
	char keycode;
    uint32_t current_loc = 100;

	/* write EOI */
	wportb(PIC1_COM, PIB_EOI);


	status = rportb(KEYBOARD_STATUS_PORT);
	/* Lowest bit of status will be set if buffer is not empty */
	if (status & 0x01) {
		keycode = rportb(KEYBOARD_DATA_PORT);
		if(keycode < 0)
			return;
		callback(keyboard_map[keycode]);	
	}
}