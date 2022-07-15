#include <kernel/vga.h>
#include <kernel/interrupt.h>

void kmain(void) {
    vga_clear();
    print("Hello World");
    prepare_interrupts();
}