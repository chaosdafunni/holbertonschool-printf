## Overview of `_printf`

The `_printf` function is a custom implementation designed to replicate the functionality of the standard C `printf`. It enables formatted output to the console, just like `printf`, but with a deeper dive into the inner workings of C programming.

This function provides an excellent opportunity to explore variadic functions, format specifiers, and how C handles different data types during output.

## Key Features

- A lightweight, custom version of `printf`, known as `_printf`.
- Supports a variety of format specifiers such as `%d`, `%s`, `%c`, and others.
- Works seamlessly with integers, characters, and strings.
- Handles errors gracefully for unsupported specifiers.
- Easy to integrate into any C project for handling formatted text output.

## Usage Guide

Using `_printf` is straightforward. Simply include the necessary header file, call `_printf()` with a format string and its corresponding arguments, and enjoy the formatted output!

### Example Code

```c
#include "_printf.h"

int main() {
    int num = 24;
    char character = 'H';
    char *str = "Hello world!";

    _printf("Number: %d\n", num);
    _printf("Character: %c\n", character);
    _printf("String: %s\n", str);

    return 0;

}
```

## Authors 
William Alvarado: [github](https://github.com/chaosdafunni)
Diego Mercado: [github](https://github.com/DMC254)
