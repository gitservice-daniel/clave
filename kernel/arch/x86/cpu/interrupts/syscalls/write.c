#include <x86/syscall.h>

void sys_write(uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    printf("SYSWRITE");
    return;
}