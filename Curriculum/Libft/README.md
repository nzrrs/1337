*This project has been created as part of the 42 curriculum by nsadiki.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum in C. The goal is to build my own static library, `libft.a`, a collection of general-purpose functions that re-implements part of the standard C library, adds extra utilities, and provides linked-list tools for the next projects.

### Library content

**Character functions**
`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

**String functions**
`ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`

**Memory functions**
`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

**Conversion functions**
`ft_atoi`, `ft_itoa`

**File descriptor output functions**
`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Linked list functions** (`t_list`)
`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

Compile the library:

```bash
make
```

Other rules:

```bash
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # rebuilds everything
```

Use it in a program:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Resources

- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [Wikipedia](https://www.wikipedia.org/)
- [YouTube](https://www.youtube.com/) tutorials
- Google / web browser
- Git manual (`man git`)
- [GNU C Library (glibc) manual](https://www.gnu.org/software/libc/manual/)

### Use of AI

AI was used to review my code and to help me understand concepts and errors (for example pointers, memory allocation and edge cases). I wrote all the functions myself, and AI was also used to help draft this README.
