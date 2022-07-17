#include <x86/pic.h>
#include <x86/ports.h>

void pic_send_eoi(uint8_t irq) {
    if (irq >= 8) {
        outb(PIC2, PIC_EOI);
    } else {
        outb(PIC1, PIC_EOI);
    }
}

void pic_remap(int offset1, int offset2) {
    uint8_t a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

	outb(PIC1, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC2, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, offset1);
	io_wait();
	outb(PIC2_DATA, offset2);
	io_wait();
	outb(PIC1_DATA, 4);
	io_wait();
	outb(PIC2_DATA, 2);
	io_wait();
 
	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();
 
	outb(PIC1_DATA, a1);
	outb(PIC2_DATA, a2);
}

void irq_set_mask(uint8_t irq_line) {
    uint16_t port;
    uint8_t value;
 
    if (irq_line < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        irq_line -= 8;
    }

    value = inb(port) | (1 << irq_line);
    outb(port, value);    
}

void irq_clear_mask(uint8_t irq_line) {
    uint16_t port;
    uint8_t value;
 
    if (irq_line < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        irq_line -= 8;
    }

    value = inb(port) & ~(1 << irq_line);
    outb(port, value); 
}

uint16_t pic_get_irr(void) {
    outb(PIC1, PIC_READ_IRR);
    outb(PIC2, PIC_READ_IRR);
    return (inb(PIC2) << 8) | inb(PIC1);
}

uint16_t pic_get_isr(void) {
    outb(PIC1, PIC_READ_ISR);
    outb(PIC2, PIC_READ_ISR);
    return (inb(PIC2) << 8) | inb(PIC1);
}