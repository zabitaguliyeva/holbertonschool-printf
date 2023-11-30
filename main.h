#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap, int*);
void print_int(va_list value, int *len);
int print_int_string(char *s, int *len);
char *_reverse(char *s, int n);
char *_itoa(int value);
int _abs(int n);

#endif
