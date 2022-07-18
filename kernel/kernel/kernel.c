#include <kernel/output.h>
#include <kernel/interrupt.h>

void kmain(void) {
    clear();
    
    prepare_interrupts();
    
    printf("Hello %s", "World!");
}
