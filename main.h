#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
#endif
