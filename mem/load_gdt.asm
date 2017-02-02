;; This is for loading the GDT

bits 32
section .text

extern GDT_PTR

global load_gdt
load_gdt:
    lgdt [GDT_PTR]
    mov ax, 0x10
    jmp 0x8:reload_cs
reload_cs:
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret