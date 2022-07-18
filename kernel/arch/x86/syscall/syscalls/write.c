#include <x86/syscall.h>
#include <kernel/vga.h>
#include <kernel/lib/function.h>

void sys_write(uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    printf("SYSWRITE");
    UNUSED(arg1 + arg2 + arg3);
}