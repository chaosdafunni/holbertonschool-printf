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
    
    if (format == NULL) 
        return (-1);

    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) 
    {
        if (format[i] == '%')
        {
            i++; 
            n += handle_specifier(format + i, args); 
        }
        else
        {
            n += _putchar(format[i]); 
        }
    }

    va_end(args);
    return (n);
}
