/*

dkernel.s 

Main kernel file

*/

#include "inttypes.h"

#include "idt/idt.h"
#include "drivers/screen/simple_screen.h"
#include "drivers/keyboard/keyboard_main.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

uint32_t s_x = 0;
uint32_t s_y = 1;

void write_out(char output) {
    write_char(output, s_x, s_y);
    s_x++;
}

void dkmain(void) {

    KEYBOARD_CALLBACK kc = (KEYBOARD_CALLBACK)write_out;
    keyboard_add(kc);
    idt_init();

    
    keyboard_init();

    const char *name = "DerpKernel";
    uint32_t i = 0;

    // Clear the screen
    clear_screen();


    // Write out the message
    while(name[i] != '\0') {
        write_char(name[i], s_x, s_y);
		i += 1;
        s_x++;
	}

    // Write out the version
    write_char(' ', s_x, s_y);
    s_x++;
    write_char(VERSION_MAJOR+48, s_x, s_y);
    s_x++;
    write_char('.', s_x, s_y);
    s_x++;
    write_char(VERSION_MINOR+48, s_x, s_y);
    s_x++;

    // DON'T FORGET THIS!!!!!!
	while(1);

}