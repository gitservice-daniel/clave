#include <kernel/vga.h>
#include <kernel/lib/vfprintf.h>
#include <x86/ports.h>

#define NUM_COLS 80
#define NUM_ROWS 25

struct Character {
    uint8_t character;
    uint8_t color;
};

struct Character* buffer = (struct Character*) 0xb8000;

size_t col = 0;
size_t row = 0;

uint8_t color = VGA_COLOR_LIGHT_GRAY | VGA_COLOR_BLACK << 4;

void clear_row(size_t row) {
    struct Character empty = (struct Character) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void vga_clear() {
    for (size_t i = 0; i < NUM_COLS; i++) {
        clear_row(i);
    }

    col = 0;
    row = 0;

    update_cursor(col, row);
}

void newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Character character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS - 1);
}

void printc(char character) {
    if (character == '\n') {
        newline();
        return;
    }

    if (col >= NUM_COLS) newline();

    buffer[col + NUM_COLS * row] = (struct Character) {
        character: (uint8_t) character,
        color: color,
    };

    col++;

    update_cursor(col, row);
}

void print_int(int number) {
    char str[1024];
    itoa(number, str);
    print(str);

    for (int i = 0; i < strlen(str); i++) {
        str[i] = '\0';
    }
}

void print_hex(int number) {
    char str[1024];
    htoa(number, str);
    print(str);

    for (int i = 0; i < strlen(str); i++) {
        str[i] = '\0';
    }
}

void print(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') return;

        printc(character);
    }
}

void printf(const char* fmt, ...) {

	va_list args;
	va_start(args, fmt);

	char buf[1024] = {0};

    vfprintf(fmt, args, buf);

	va_end(args);
    print(buf);
}

void vga_set_color(uint8_t foreground, uint8_t background) {
    color = foreground | background << 4;
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end) {
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void disable_cursor() {
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void update_cursor(int x, int y) {
	uint16_t pos = y * NUM_COLS + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}