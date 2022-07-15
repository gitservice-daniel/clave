#include <x86/idt.h>
#include <stdbool.h>

static idt_entry_t idt[MAX_IDT_ENTRIES];
static idtr_t idtr;

extern void* isr_stub_table[];

static bool vectors[MAX_IDT_ENTRIES];

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    idt_entry_t* descriptor = &idt[vector];

    descriptor->isr_low = (uint32_t) isr & 0xffff;
    descriptor->kernel_cs = 0x08;
    descriptor->attributes = flags;
    descriptor->isr_high = (uint32_t) isr >> 16;
    descriptor->reserved = 0;
}

void idt_free_descriptor(uint8_t vector) {
    idt_set_descriptor(vector, 0, 0);
    vectors[vector] = false;
}

void idt_init(void) {
    idtr.base = (uintptr_t) &idt[0];
    idtr.limit = (uint16_t) sizeof(idt_entry_t) * MAX_IDT_ENTRIES - 1;

    for (uint8_t vector = 0; vector < 32; vector++) {
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8e);
        vectors[vector] = true;
    }

    asm volatile("lidt %0" : : "m"(idtr));
    asm volatile("sti");
}