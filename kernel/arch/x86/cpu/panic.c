#include <kernel/panic.h>
#include <kernel/output.h>

void panic(char* reason, char* details) {
    clear();

    printf("Kernel panic: %s\n\nYour Computer has ran into a problem that it couldn't handle.\nPlease restart your Computer.\n\nDetails: %s", reason, details);

    asm("cli");
    while (1) {
        asm("hlt");
    }
}