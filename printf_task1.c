#include <stdio.h>
#include <stdarg.h>

/**
 * int_to_str - Convert an integer to a string.
 * @num: The integer to convert.
 * @buffer: The buffer to store the string representation.
 */

void int_to_str(int num, char *buffer)
{
        int i = 0, is_negative = 0;

        if (num < 0)
        {
                is_negative = 1;
                num = -num;
        }
        do {
                buffer[i++] = (num % 10) + '0';
                num /= 10;
        } while (num > 0);

        if (is_negative)
                buffer[i++] = '-';

        buffer[i] = '\0';

        for (int j = 0, k = i - 1; j < k; ++j, --k)
        {
                char temp = buffer[j];
                buffer[j] = buffer[k];
                buffer[k] = temp;
        }
}

/**
 * my_printf - A simplified version of printf supporting %d and %i.
 * @format: The format string.
 */

void my_printf(const char *format, ...)
{
        va_list args;
        const char *p;

        va_start(args, format);
        p = format;

        while (*p)
        {
                if (*p == '%' && *(p + 1))
                {
                        p++;
                        switch (*p)
                        {
                                case 'd':
                                case 'i':
                                        {
                                                int num = va_arg(args, int);
                                                char buffer[20];

                                                int_to_str(num, buffer);
                                                for (char *s = buffer; *s; ++s)
                                                        putchar(*s);
                                                break;
                                        }
                                default:
                                        putchar('%');
                                        putchar(*p);
                        }
                }
                else
                {
                        putchar(*p);
                }
                p++;
        }
        va_end(args);
}

/**
 * main - Entry point to demonstrate the custom printf function.
 *
 * Return: Always 0.
 */

int main(void)
{
        my_printf("The value is %d and %i.\n", 123, -456);
        my_printf("Simple test with no specifiers.\n");
        my_printf("Unknown specifier %%x will be ignored.\n");

        return (0);
}
