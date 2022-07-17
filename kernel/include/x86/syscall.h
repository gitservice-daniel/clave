#pragma once

#include <stdint.h>

extern void common_syscall_handler();

void install_syscall(void);
void syscall_handler_void(uint32_t id, uint32_t arg1, uint32_t arg2, uint32_t arg3);

void sys_exit(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void sys_write(uint32_t arg1, uint32_t arg2, uint32_t arg3);