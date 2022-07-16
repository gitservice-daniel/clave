#include <kernel/vga.h>
#include <kernel/interrupt.h>

void kmain(void) {
    vga_clear();
    enable_cursor(12, 14);

    prepare_interrupts();

    print("Hello World");
}
