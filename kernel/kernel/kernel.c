#include <kernel/vga.h>

void kmain(void) {
    vga_clear();
    print("Hello World");
    enable_cursor(12, 14);
}
