#include "string.h"

void long_to_str(uint32_t input, char * output) {
    uint32_t mask = 0x0;
    uint32_t temp;
    uint8_t i = 0;

    for (i = 0; i < 8; i++) {
        mask = 0xF << (i*4);
        temp = (input & mask) >> (i*4);
        if (temp < 10) {
            output[7-i] = temp + 48;
        } else {
            output[7-i] = temp + 55;
        }
        
    }
    output[8] = 0;
}