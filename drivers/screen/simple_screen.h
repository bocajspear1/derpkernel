/*

simple_screen.h

Simple screen does screen output for the
VGA spec. (https://en.wikipedia.org/wiki/Video_Graphics_Array)
This means we have a grid of 80 X 25

*/
#ifndef SIMPLE_SCREEN
#define SIMPLE_SCREEN

#include "inttypes.h"

#define TERM_WIDTH 80
#define TERM_HEIGHT 25

void clear_screen();
void newline();
void write_char(char c);
void write_string(const char * out_str);
void set_location(uint16_t x, uint16_t y);

uint16_t get_x();
uint16_t get_y();

#endif