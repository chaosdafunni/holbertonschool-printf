#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

int _putchar(char c);
int handlers_c(va_list args);
int handlers_s(va_list args, int n);
int handlers_di(va_list args);
int handle_specifier(const char *format, va_list args);
int _printf(const char *format, ...);

#endif
