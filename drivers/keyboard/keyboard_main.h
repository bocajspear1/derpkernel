#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "inttypes.h"
#include "../../idt/idt.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

typedef void (*KEYBOARD_CALLBACK)();

void keyboard_add(KEYBOARD_CALLBACK);
void keyboard_init();

KEYBOARD_CALLBACK callback;



#endif //KEYBOARD_H