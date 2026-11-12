*This project has been created as part of the 42 curriculum by nsadiki.*

# get_next_line

Read a file one line at a time, using only a file descriptor.

## Description

`get_next_line` implements:

```c
char	*get_next_line(int fd);
```

Each call returns the next line, including `\n` when it is present. It returns
`NULL` when there is nothing left to read or when an error occurs.

The project is about understanding `read`, file descriptors, dynamic memory,
and how data can survive between function calls.

## How it works

The function keeps unread characters in a **stash**:

1. Read a chunk of bytes into a temporary buffer.
2. Append the chunk to the stash until a newline is found.
3. Return the first complete line.
4. Keep the remaining characters for the next call.

This algorithm is necessary because one `read` call can return part of a line,
one complete line, or several lines. The stash prevents data from being lost.
The mandatory version uses one static stash, which is simple and matches the
project requirements. Its trade-off is that each append copies the existing
stash, keeping the implementation clear at the cost of some performance.

## Instructions

There is no `Makefile` in this project. Compile it with a chosen
`BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

If `BUFFER_SIZE` is not provided, the header uses `4096`.

Example:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("input.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

Run the program with:

```bash
./get_next_line
```

The caller owns each returned line and must free it.

## Bonus

The bonus version must:

- use only one static variable;
- read from several file descriptors without mixing their state;
- keep a separate stash for each `fd`.

For example, calls may alternate between file descriptors `3`, `4`, and `5`
without losing any buffered data. A static array of stash pointers indexed by
file descriptor is a straightforward way to meet this requirement.

The bonus files are:

```text
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c
```

## Resources

- [`read(2)` manual page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`open(2)` and `close(2)` manual pages](https://man7.org/linux/man-pages/man2/open.2.html)
- [`malloc(3)` manual page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [42 get_next_line subject](https://cdn.intra.42.fr/pdf/pdf/41344/en.subject.pdf)

### AI usage

AI was used to review the README requirements, improve the documentation
structure, and explain the stash algorithm. The C implementation and its tests
were written and checked manually.
