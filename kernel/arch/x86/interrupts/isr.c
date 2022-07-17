#include <x86/isr.h>
#include <kernel/vga.h>
#include <kernel/panic.h>
#include <kernel/string.h>

char* exception_name[] = {
    "Division By Zero",
    "Debug",
    "Non-maskable Interrupt",
    "Breakpoint",
    "Detected Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack-Segment Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "x87 Floating-Point Exception",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating-Point Exception",
    "Virtualization Exception",
    "Control Protection Exception",
    "Reserved",
    "Hypervisor Injection Exception",

    "VMM Communication Exception",
    "Security Exception",
    "Reserved",
    "Triple Fault",
};

/** 
 *  CPU Exception Types 
 *
 *  0 = Fault (Correct this Exception, program can may continue)
 *  1 = Traps (Reported after execution of program)
 *  2 = Abort (A unrecoverable Error)
 *  4 = Interrupt (Is just a Interrupt)
 *  5 = Reserved (No information)
 */
int exception_type[] = {
    0, 0, 4, 1, 1, 0, 
    0, 0, 2, 0, 0, 0, 
    0, 0, 0, 5, 0, 0, 
    2, 0, 0, 0, 5, 0, 
    0, 0, 5, 5, 4, 5,
};

void exception_handler(void) {
    register int i asm("eax");

    int type = exception_type[i];
    char* name = exception_name[i];

    if (type == 0) {
        return;
    } else if (type == 1) {
        return; // handle this
    } else if (type == 3) {
        return; // handle this
    } else if (type == 4) {
        return; // handle this
    } else if (type == 5) {
        return;
    } else {
        panic("CPU Exception", name);
    }
}