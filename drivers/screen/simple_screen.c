#include "simple_screen.h"

char *VIDPTR = (char*)0xb8000;

// We clear the screen by just writing blank characters
// to video memory
void clear_screen() {
    unsigned int j = 0;
    while(j < TERM_WIDTH * TERM_HEIGHT * 2) {
		/* blank character */
		VIDPTR[j] = ' ';
		
		VIDPTR[j+1] = 0x02; 		
		j = j + 2;
	}
}

void write_char(char c, int x, int y) {
    // Check out bounds
    if (x > TERM_WIDTH) {
        x = TERM_WIDTH;
    }
    if (y > TERM_HEIGHT) {
        y = TERM_HEIGHT;
    }
    // Write the character
    unsigned int loc = (TERM_WIDTH * 2) * y + (x * 2);
    VIDPTR[loc] = c;

    // Write the attribute byte
    VIDPTR[loc+1] = 0x02;
}

void write_string(const char * out_str, int x, int y) {
    int loc = 0;

    while (*(out_str+loc) != '\0') {
        write_char(*(out_str+loc), x, y);
        x++;
        if (x > TERM_WIDTH) {
            x = 0;
            y++;
        }
        loc++;
    }
}