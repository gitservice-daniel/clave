#include <x86/cpuid.h>

void cpuid(int code, uint32_t* a, uint32_t* d) {
    asm volatile( "cpuid" : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx" );
}