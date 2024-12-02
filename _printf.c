#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 *
 * @format: format string containing the characters and specifiers
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int n = 0;

	va_start(args, *format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_specifier(format, args);
		}
		else
		{
			n += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (n + 1);

}
