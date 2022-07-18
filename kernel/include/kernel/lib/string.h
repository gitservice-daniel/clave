#pragma once

#include <stddef.h>

void itoa(int n, char str[]);
void htoa(int n, char str[]);
void reverse(char s[]);
int strlen(char s[]);
void backspace(char s[]);
void append(char s[], char n);
int strcmp(char s1[], char s2[]);
void strcpy(char* dest, const char* src);
int strnlen(const char* str, int len);
char* strcat(char* dest, const char* src);
char* strchr(const char* str, int chr);