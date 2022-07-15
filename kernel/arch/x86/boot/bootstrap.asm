section .text

global _start
extern kmain
extern gdt_descriptor

_start:
    cli

    lgdt[gdt_descriptor]

    jmp 0x0008:fix_cs

fix_cs:
    mov ax, 0x0010
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov esp, stack_top

    call kmain

    cli
    hlt
    jmp $

section .bss
align 16

stack_bottom:
    resb 16384
stack_top: