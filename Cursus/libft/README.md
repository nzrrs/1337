*This project has been created as part of the 42 curriculum by nsadiki.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum in C. The goal is to build my own static library, `libft.a`, a collection of general-purpose functions that:

- re-implements part of the standard C library (`libc`),
- adds extra utility functions that are not in the standard library,
- provides linked-list tools (`t_list`) that will be reused in the next projects.

The library is compiled with `cc -Wall -Wextra -Werror` and archived with `ar`. The project teaches pointers, memory allocation (`malloc`/`free`), string manipulation, edge-case handling and the use of a `Makefile`.

### Library content

#### Character functions (`libc` re-implementations)

| Function | Description |
|---|---|
| `ft_isalpha` | Returns non-zero if `c` is an alphabetic character (`A-Z`, `a-z`), otherwise 0. |
| `ft_isdigit` | Returns non-zero if `c` is a decimal digit (`0-9`), otherwise 0. |
| `ft_isalnum` | Returns non-zero if `c` is a letter or a digit, otherwise 0. |
| `ft_isascii` | Returns non-zero if `c` is in the ASCII range (0 to 127), otherwise 0. |
| `ft_isprint` | Returns non-zero if `c` is a printable character (32 to 126), otherwise 0. |
| `ft_toupper` | Converts a lowercase letter to uppercase; any other character is returned unchanged. |
| `ft_tolower` | Converts an uppercase letter to lowercase; any other character is returned unchanged. |

#### String functions (`libc` re-implementations)

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string, not counting the terminating `'\0'`. |
| `ft_strlcpy` | Copies up to `size - 1` characters from `src` to `dst` and always null-terminates (if `size > 0`). Returns the length of `src`. |
| `ft_strlcat` | Appends `src` to `dst`, never writing more than `size` bytes in total, and null-terminates. Returns the length it tried to create (initial length of `dst` + length of `src`). |
| `ft_strchr` | Returns a pointer to the first occurrence of character `c` in a string (the terminating `'\0'` counts), or `NULL`. |
| `ft_strrchr` | Returns a pointer to the last occurrence of character `c` in a string, or `NULL`. |
| `ft_strncmp` | Compares at most `n` characters of two strings and returns the difference between the first differing bytes (as `unsigned char`). |
| `ft_strnstr` | Locates the first occurrence of `little` inside `big`, searching at most `len` characters. Returns a pointer to it, `big` if `little` is empty, or `NULL`. |
| `ft_strdup` | Returns a newly allocated copy of a string (must be freed). |

#### Memory functions (`libc` re-implementations)

| Function | Description |
|---|---|
| `ft_memset` | Fills the first `n` bytes of a memory area with the byte `c`. |
| `ft_bzero` | Sets the first `n` bytes of a memory area to zero. |
| `ft_memcpy` | Copies `n` bytes from `src` to `dst`. The areas must not overlap. |
| `ft_memmove` | Copies `n` bytes from `src` to `dst`, and handles overlapping areas correctly. |
| `ft_memchr` | Returns a pointer to the first occurrence of byte `c` in the first `n` bytes of a memory area, or `NULL`. |
| `ft_memcmp` | Compares the first `n` bytes of two memory areas and returns the difference between the first differing bytes. |
| `ft_calloc` | Allocates memory for `nmemb` elements of `size` bytes each and initializes it to zero. Returns `NULL` on allocation failure or multiplication overflow. |

#### Conversion functions (`libc` re-implementations)

| Function | Description |
|---|---|
| `ft_atoi` | Converts the beginning of a string to an `int`. Skips leading whitespace and accepts an optional `+` or `-` sign. |

#### Additional functions (not in `libc`)

| Function | Description |
|---|---|
| `ft_substr` | Returns a newly allocated substring of `s`, starting at index `start`, with a maximum length `len`. |
| `ft_strjoin` | Returns a newly allocated string that is the concatenation of `s1` and `s2`. |
| `ft_strtrim` | Returns a newly allocated copy of `s1` with all characters found in `set` removed from the beginning and the end. |
| `ft_split` | Splits a string using a character `c` as delimiter. Returns a newly allocated, `NULL`-terminated array of newly allocated strings. |
| `ft_itoa` | Converts an `int` to a newly allocated string, handling negative numbers and `INT_MIN`. |
| `ft_strmapi` | Applies a function `f(index, char)` to every character of a string and returns a newly allocated string with the results. |
| `ft_striteri` | Applies a function `f(index, &char)` to every character of a string, modifying it in place. |

#### File descriptor output functions

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to the given file descriptor. |
| `ft_putstr_fd` | Writes a string to the given file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to the given file descriptor. |
| `ft_putnbr_fd` | Writes an integer in decimal to the given file descriptor. |

#### Linked list functions (`t_list`)

The list node is defined as:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node whose `content` is the given pointer and whose `next` is `NULL`. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Returns the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees one node's content with the function `del`, then frees the node itself. |
| `ft_lstclear` | Deletes and frees a node and all the nodes after it, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Applies a function to the content of every node and builds a new list of the results, cleaning up with `del` if an allocation fails. |

## Instructions

### Compilation

Compile the library from the root of the repository:

```bash
make
```

This produces the static library `libft.a`.

Other rules:

```bash
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # rebuilds everything
```

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

### Execution

```bash
./my_program
```

## Resources

### References

- [GeeksforGeeks](https://www.geeksforgeeks.org/): C strings, pointers, dynamic memory allocation and linked lists.
- [Wikipedia](https://www.wikipedia.org/): background on linked lists and ASCII.
- [YouTube](https://www.youtube.com/) tutorials: pointers, `malloc`/`free` and Makefiles.
- [GNU C Library (glibc) manual](https://www.gnu.org/software/libc/manual/): reference behavior of the `libc` functions re-implemented here.
- Manual pages (`man 3 strlcpy`, `man 3 memmove`, ...): expected behavior and return values.
- Git manual (`man git`): version control.

### Use of AI

AI was used as a learning and review tool, not to write the functions. Tasks and parts of the project concerned:

- **Understanding concepts**: pointers, memory allocation (`malloc`/`free`) and how they apply to the string and memory functions.
- **Understanding errors**: compilation errors and unexpected results met while writing the functions.
- **Reviewing code**: reviewing functions I had already written, mainly to find edge cases (empty strings, `NULL` handling, size limits, memory leaks).
- **Documentation**: helping draft this `README.md`.

I wrote all the functions myself, and I tested and understood all the code submitted.
