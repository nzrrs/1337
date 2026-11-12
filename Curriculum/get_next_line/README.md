*This project has been created as part of the 42 curriculum by nsadiki.*

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from a
file descriptor. A line includes the terminating newline character when one is
present. When the end of the file is reached, the function returns the final
line if it contains data, then returns `NULL` on subsequent calls.

The goal of the project is to understand file descriptors, the `read` system
call, dynamic memory allocation, string manipulation, and how to preserve data
between function calls. This implementation uses a static stash to keep
characters that were read after the end of the current line.

The public function is:

```c
char	*get_next_line(int fd);
```

The returned string is allocated dynamically and must be freed by the caller.

## Instructions

### Compilation

This project does not include a `Makefile`. Compile the source files with
`cc`, choosing a `BUFFER_SIZE` appropriate for the test:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

`BUFFER_SIZE` may be changed without modifying the source code. If it is not
defined during compilation, the header uses `4096` as a fallback value.

### Usage

Open a file, call `get_next_line` until it returns `NULL`, and free each line:

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
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Run the compiled program with:

```bash
./get_next_line
```

The function returns `NULL` for an invalid file descriptor, an invalid
`BUFFER_SIZE`, a read error, or when there is no more data to return.

## Algorithm

The implementation uses a dynamically allocated **stash** and a fixed-size
read buffer:

1. `get_next_line` validates the file descriptor and allocates a temporary
   buffer of `BUFFER_SIZE + 1` bytes.
2. `fill_stash` repeatedly calls `read` while the stash does not contain a
   newline. Each chunk is null-terminated and appended to the stash.
3. `extract_line` searches for the first newline. If it finds one, it returns
   everything through that newline; otherwise, it returns the remaining
   characters as the final line.
4. `trim_stash` removes the line that was returned and keeps any characters
   after the newline for the next call.
5. The stash is stored in a static variable, so it survives after
   `get_next_line` returns.

This approach is appropriate because `read` can return a partial line or
several lines in one call. Keeping the unread remainder avoids losing data and
means each call returns exactly one line. The implementation uses a single
static stash, so it is designed for reading one file descriptor at a time.

The trade-off is that each append allocates a new string and copies the
existing stash. This keeps the code simple and clear for the project while
using only standard system calls and dynamic memory allocation.

## Resources

- [`read(2)` manual page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`open(2)` manual page](https://man7.org/linux/man-pages/man2/open.2.html)
- [`close(2)` manual page](https://man7.org/linux/man-pages/man2/close.2.html)
- [`malloc(3)` manual page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [42 subject: get_next_line](https://cdn.intra.42.fr/pdf/pdf/41344/en.subject.pdf)
- [Beej's Guide to Unix IPC: file descriptors](https://beej.us/guide/bgipc/html/split/index.html)

### Use of AI

AI was used for documentation tasks in this project: checking the README
against the 42 README requirements, organizing the sections, and helping
explain the stash-based line-reading algorithm and its trade-offs. AI was not
used to replace the implementation or testing of the C source files.