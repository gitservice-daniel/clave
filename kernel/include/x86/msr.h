#pragma once
 
#include <stdint.h>
#include <stdbool.h>

#define MAX_IDT_ENTRIES 256

bool check_msr();
 
void rdmsr(uint32_t msr, uint32_t* lo, uint32_t* hi);
void wrmsr(uint32_t msr, uint32_t lo, uint32_t hi);