*This project has been created as part of the 42 curriculum by nsadiki.*

# ft_printf

## Description

ft_printf is my own version of the C `printf` function. The goal is to learn how variadic functions work (`va_list`, `va_start`, `va_arg`, `va_end`) by rebuilding it from scratch.

It builds a static library, `libftprintf.a`, with one function:

```c
int ft_printf(const char *format, ...);
```

It prints to standard output and returns the number of characters printed, or `-1` if `write` fails.

Supported conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`

## Instructions

Compile the library:

```bash
make all
```

`make` alone does the same. Other rules: `make clean`, `make fclean`, `make re`.

Use it in a program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, number: %d, hex: %x\n", "world", 42, 255);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Algorithm

No complex data structure is needed. `printf` is a single pass over the format string.

1. `ft_printf` reads the format string one character at a time.
2. A normal character is written directly with `write`.
3. After a `%`, the next character is sent to a dispatcher (`ft_handler`), which calls the right function for that conversion.
4. Each function returns the number of characters it wrote. `ft_printf` adds them to a total.
5. If any call returns `-1`, the error is passed up and `ft_printf` returns `-1`.

Why this design: one small function per conversion keeps the code simple, readable and Norm-friendly. Adding a new conversion only means adding one case in the dispatcher.

The `va_list` is passed as a pointer (`va_list *`) so every handler moves forward in the same argument list. Passing it by value is not safe once `va_arg` is used on it.

Numbers are printed with one base conversion function (base 10 or base 16 using a base string). Pointers are cast to `unsigned long` and printed in hexadecimal after `0x`.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [GeeksforGeeks: Variadic functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/)
- Google searches (va_list, base conversion, `write` return values)

AI usage: I wrote the code myself. I used AI only to check my understanding of `va_list` (passing it as a pointer), to discuss error handling when `write` succeeds but the next call fails, to split `ft_printf` into two functions for the Norm, and to draft this README.
