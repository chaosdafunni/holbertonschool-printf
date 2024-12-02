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
    
    if (format == NULL) // Check if the format string is NULL
        return (-1);

    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) // Using a for loop instead of a while loop
    {
        if (format[i] == '%')
        {
            i++; // Skip the '%' character
            n += handle_specifier(format + i, args); // Call handle_specifier directly and update count
        }
        else
        {
            n += _putchar(format[i]); // Print regular characters
        }
    }

    va_end(args);
    return n; // Return the total number of characters printed
}
