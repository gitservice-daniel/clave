#include <kernel/interrupt.h>
#include <x86/idt.h>
#include <x86/syscall.h>
#include <x86/pic.h>

void prepare_interrupts(void) {
    install_cpu_exceptions();
    pic_remap(PIC1, PIC2);
    install_syscall();
    set_idt();
}