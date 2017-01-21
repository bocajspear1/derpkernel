#include "drivers/screen/simple_screen.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

void dkmain(void) {
    const char *name = "DerpKernel";
    char *vidptr = (char*)0xb8000;
    unsigned int i = 0;

    // Clear the screen
    clear_screen();

    unsigned int s_x = 0;
    unsigned int s_y = 1;

    // Write out the message
    while(name[i] != '\0') {
        write_char(name[i], s_x, s_y);
		i += 1;
        s_x++;
	}

    write_char(' ', s_x, s_y);
    s_x++;
    write_char(VERSION_MAJOR+48, s_x, s_y);
    s_x++;
    write_char('.', s_x, s_y);
    s_x++;
    write_char(VERSION_MINOR+48, s_x, s_y);
    s_x++;

	return;

}