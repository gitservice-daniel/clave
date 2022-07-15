#include <kernel/interrupt.h>
#include <x86/idt.h>

void prepare_interrupts(void) {
    idt_init();
}