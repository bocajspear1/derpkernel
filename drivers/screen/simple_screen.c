#include "simple_screen.h"

char *VIDPTR = (char*)0xb8000;
uint16_t SIMPLE_SCREEN_X = 0;
uint16_t SIMPLE_SCREEN_Y = 0;

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

uint16_t get_x() {
    return SIMPLE_SCREEN_X;
}

uint16_t get_y() {
    return SIMPLE_SCREEN_Y;
}

void newline() {
    SIMPLE_SCREEN_X = 0;
    SIMPLE_SCREEN_Y += 1;
}

void write_char(char c) {
    // Write the character
    unsigned int loc = (TERM_WIDTH * 2) * SIMPLE_SCREEN_Y + (SIMPLE_SCREEN_X * 2);
    VIDPTR[loc] = c;

    // Write the attribute byte
    VIDPTR[loc+1] = 0x02;
    SIMPLE_SCREEN_X++;
    if (SIMPLE_SCREEN_X > TERM_WIDTH) {
        newline();
    }
}

void write_string(const char * out_str) {
    int loc = 0;
    while (*(out_str+loc) != '\0') {
        write_char(*(out_str+loc));
        loc++;
    }
}

void set_location(uint16_t x, uint16_t y) {
    if (x > TERM_WIDTH) {
        x = TERM_WIDTH;
    }
    if (y > TERM_HEIGHT) {
        y = TERM_HEIGHT;
    }
    SIMPLE_SCREEN_X = x;
    SIMPLE_SCREEN_Y = y;
}