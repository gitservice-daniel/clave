#include <kernel/output.h>
#include <kernel/lib/vfprintf.h>
#include <x86/vga.h>
#include <stdarg.h>

#define VGAOUT 0

#define STDIN  VGAOUT
#define STDOUT VGAOUT
#define STDERR VGAOUT

void print(char* buffer) {
    fprint(STDIN, buffer);
}

void printf(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char buffer[1024] = {0};

    vfprintf(fmt, args, buffer);

	va_end(args);
    print(buffer);
}

void fprint(int stream, char* buffer) {
    switch (stream) {
        case VGAOUT:
            vga_print(buffer);
            break;
        default:
            break;
    }
}

void textcolor(uint8_t foreground, uint8_t background) {
    vga_set_color(foreground, background);
}

void clear(void) {
    vga_clear();
}

void read(void) {
    /**
      * TODO: Implement read()
      */
}