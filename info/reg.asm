;; This is for getting info from registers

bits 32
section .text

global get_mode
get_mode:
    xor eax, eax
    mov eax, cr0
    and eax, 0x00000001
    ret