#include <x86/syscall.h>
#include <x86/idt.h>
#include <kernel/vga.h>

void install_syscall(void) {
    idt_set_descriptor(80, common_syscall_handler, 0x8e);
}

/** 
  * id   = eax
  * arg1 = edi
  * arg2 = esi
  * arg3 = edx
  */
void syscall_handler(uint32_t id, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    switch (id) {
        /* sys_exit */
        case 0:
            sys_exit(arg1, arg2, arg3);
            break;

        /* sys_write */
        case 1:
            sys_write(arg1, arg2, arg3);
            break;

        /* do nothing, maybe handle this later */
        default:
            break;
    }
}