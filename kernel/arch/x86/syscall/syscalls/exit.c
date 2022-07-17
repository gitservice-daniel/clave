#include <x86/syscall.h>
#include <kernel/vga.h>
#include <kernel/function.h>

void sys_exit(uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    printf("SYSEXIT");
    UNUSED(arg1 + arg2 + arg3);
}