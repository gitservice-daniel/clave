#include <x86/syscall.h>
#include <kernel/vga.h>

void sys_exit(uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    printf("SYSEXIT");
    return;
}