section .text

global _start
extern kmain

_start:
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