#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

enum {
    VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GRAY = 7,
	VGA_COLOR_DARK_GRAY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_PINK = 13,
	VGA_COLOR_YELLOW = 14,
	VGA_COLOR_WHITE = 15,
};

void vga_clear();
void vga_set_color(uint8_t foreground, uint8_t background);

void vga_printc(char character);
void vga_print(char* str);

void vga_enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void vga_disable_cursor(void);
void vga_update_cursor(int x, int y);