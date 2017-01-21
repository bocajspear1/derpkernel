;; This is for reading IO ports

bits 32
section .text

global rportb
global wportb

rportb:
    mov edx, [esp + 4]
    in al, dx
    ret

wportb:
    mov edx, [esp + 4]
    mov al, [esp + 4 + 4]
    out dx, al
    ret
