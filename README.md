# DerpKernel

A derpy kernel made for fun, suffering, learning and a whole bunch of stuff.

Learning lower level stuff!

# Overview

Main kernel files are `dkernel.c` and `dkernel_start.asm`.

Drivers are in the `drivers` folder.

`info` contains functions for getting system info.

`mem` is for memory functions.

# Building

For Ubuntu, you'll need, `gcc-mulilib`, `nasm`, `qemu` and `make`. 

Run `make` to build the kernel, and `make run` to run it.

# Sources (In about order of use):


* [Kernel 101 – Let’s write a Kernel](http://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel)
* [Kernel 201 – Let’s write a Kernel with keyboard and screen support](http://arjunsreedharan.org/post/99370248137/kernel-201-lets-write-a-kernel-with-keyboard)
* [The GDT](http://www.osdever.net/bkerndev/Docs/gdt.htm)
* [Global Descriptor Table](http://wiki.osdev.org/Global_Descriptor_Table)
* [GDT Tutorial](http://wiki.osdev.org/GDT_Tutorial)
