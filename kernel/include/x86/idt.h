#pragma once

#include <stdint.h>
#include <stdbool.h>

#define MAX_IDT_ENTRIES 256

typedef struct {
    uint16_t isr_low;
    uint16_t kernel_cs;
    uint8_t reserved;
    uint8_t attributes;
    uint16_t isr_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idtr_t;

static idt_entry_t idt[MAX_IDT_ENTRIES];
static idtr_t idtr;

static bool vectors[MAX_IDT_ENTRIES];

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags);
void idt_free_descriptor(uint8_t vector);

void set_idt(void);
void install_cpu_exceptions(void);