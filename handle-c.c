#include "main.h"

/**
 * handle_specifier - Processes a single format
 *
 * @format: format specifier to handle
 * @args: list of args for the specifier
 *
 * Return: ct
 */

int handle_specifier(const char *format, va_list args)
{
	int ct = 0;

	if (*format == '%')
	{
		ct += _putchar('%');
		return (ct);
	}

	switch (*format)
	{
		case 'c':
			ct += handlers_c(args);
			break;
		case 's':
			ct += handlers_s(args, ct);
			break;
		case 'i':
		case 'd':
			ct += handlers_di(args);
			break;
		default:
			ct += _putchar('%');
			ct += _putchar(*format);
			break;
	}
	return (ct);
}

/**
 * handlers_c - handles the 'c' format
 *
 * @args: list of var arguments passed to printf
 *
 * Return: cr
 */

int handlers_c(va_list args)
{
	char cr = va_arg(args, int);

	_putchar(cr);
	return (cr);
}

/**
 * handlers_s - handles the 's' format 
 *
 * @args: list of var arguments passed to printf
 * @n: count
 *
 * Return: n
 */

int handlers_s(va_list args, int n)
{
	char *sg = va_arg(args, char *);

	while (*sg != '\0')
	{
	n += _putchar(*sg);
	sg++;
	}
	return (n);
}

/**
 * handlers_di - handles the conversion of 'd' and 'i'
 *
 * @args: variadic arguments list containing integers
 *
 * Return: count
 */

int handlers_di(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	char buffer[20];
	int m = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	do

	{
		buffer[m++] = (num % 10) + '0';
		num /= 10;
	}

	while (num > 0);

	while (m--)
	{
		count += _putchar(buffer[m]);
	}
	return (count);
}
