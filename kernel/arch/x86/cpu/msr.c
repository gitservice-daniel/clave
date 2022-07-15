#include <x86/msr.h>
#include <x86/cpuid.h>

const uint32_t CPUID_FLAG_MSR = 1 << 5;
 
bool check_msr() {
   uint32_t a, d;
   cpuid(1, &a, &d);
   return d & CPUID_FLAG_MSR;
}
 
void rdmsr(uint32_t msr, uint32_t* lo, uint32_t* hi) {
   asm volatile("rdmsr" : "=a"(*lo), "=d"(*hi) : "c"(msr));
}
 
void wrmsr(uint32_t msr, uint32_t lo, uint32_t hi) {
   asm volatile("wrmsr" : : "a"(lo), "d"(hi), "c"(msr));
}