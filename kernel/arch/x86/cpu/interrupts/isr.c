#include <x86/isr.h>
#include <kernel/vga.h>

void exception_handler(void) {
    vga_clear();
    print("ERR EXCEPTION");

    asm volatile("cli");
    while (1) {
        asm volatile("hlt");
    }
}