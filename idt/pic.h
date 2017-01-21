/*

This defines the PIC values

See:
http://arjunsreedharan.org/post/99370248137/kernel-201-lets-write-a-kernel-with-keyboard
http://wiki.osdev.org/PIC

*/
#ifndef PIC_H
#define PIC_H

#include "inttypes.h"

// Master PIC
#define PIC1_COM 0x20
#define PIC1_DAT 0x21

// Slave PIC
#define PIC2_COM 0xA0
#define PIC2_DAT 0xA1

#define PIC_INIT 0x11 //ICW1
#define PIC_OFFSET 0x20 //ICW2

// From http://wiki.osdev.org/PIC
#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */


#define PIB_EOI 0x20

#endif //PIC_H