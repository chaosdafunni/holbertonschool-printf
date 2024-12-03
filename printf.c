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

	va_start(args, format);
	if (!format)
	{
		return (-1);
	}
	for (int i = 0; format[i] != '\0'; i++) 
	{
		if (*format == '%')
		{
			format++;
			n +=  handle_specifier(format, args);
		}
		else
		{
			n += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (n);

}
