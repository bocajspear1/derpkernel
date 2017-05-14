/*

dkernel.s 

Main kernel file

*/

#include "inttypes.h"

#include "idt/idt.h"
#include "mem/gdt.h"
#include "pci/pci.h"
#include "drivers/screen/simple_screen.h"
#include "drivers/keyboard/keyboard_main.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define ENTER_KEY_CODE 0x1C

extern int get_mode(void);

void write_out(char output) {
    if (output == '\n') {
        newline();
    } else if (output == '\b') {
        if (get_x() > 0) {
            set_location(get_x()-1, get_y());
            write_char(' ');
        } else {
            write_char(' ');
        }
    } else {
        write_char(output);
    }
}

void boot(void) {
    clear_screen();
    set_location(0,0);
    write_string("Booting...");
    KEYBOARD_CALLBACK kc = (KEYBOARD_CALLBACK)write_out;
    keyboard_add(kc);
    idt_init();
    gdt_init();
    uint8_t result = pci_enumerate();
    result += 48;
    set_location(5,5);
    write_char(result);
}

void dkmain(void) {

    boot();
    keyboard_init();

    set_location(0, 1);
    const char *name = "Welcome to DerpKernel";

    write_string(name);

    // Clear the screen
    // clear_screen();

    // write_char(get_mode()+0x30, s_x, s_y);
    // s_x++;

    // Write out the version
    write_char(' ');
    write_char(VERSION_MAJOR+48);
    write_char('.');
    write_char(VERSION_MINOR+48);

    newline();

    // DON'T FORGET THIS!!!!!!
	while(1);

}