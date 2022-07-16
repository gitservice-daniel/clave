#include <kernel/panic.h>
#include <kernel/vga.h>

void panic(char* reason, char* details) {
    vga_clear();
    disable_cursor();

    print("Kernel panic: ");
    print(reason);
    print("\n\nYour Computer has ran into a problem that it couldn't handle.\n");
    print("Please restart your Computer.\n");
    print("\nDetails: ");
    print(details);

    asm("cli");
    while (1) {
        asm("hlt");
    }
}