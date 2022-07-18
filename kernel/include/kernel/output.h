#pragma once

#include <stdint.h>

void print(char* str);
void printf(const char* fmt, ...);
void fprintf(int stream, char* buffer);
void textcolor(uint8_t foreground, uint8_t background);
void clear(void);
void read(void);