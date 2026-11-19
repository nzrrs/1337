*This project has been created as part of the 42 curriculum by nsadiki.*

# get_next_line

## Description

`get_next_line` reads and returns one line from a file descriptor on each call. The line includes the newline character when one is present, and returns `NULL` when there is no more data or an error occurs.

The mandatory version keeps data for one file descriptor. The bonus version can read from multiple file descriptors at the same time.

## Instructions

Compile the mandatory version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c main.c -o test
```

Compile the bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o test
```

Use the function in a `main`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
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

For the bonus version, include `get_next_line_bonus.h` instead.

## Algorithm

The mandatory version uses a static `stash` to keep data that was read after the current line. This lets the next call continue where the previous call stopped.

`fill_stash` reads up to `BUFFER_SIZE` bytes and joins each buffer to the stash until it finds a newline or reaches EOF. Joining the chunks makes the function work when a line is longer than one read.

`extract_line` copies the first line from the stash, including `\n` when it exists. `trim_stash` then replaces the stash with the data after that newline, or frees it when no remainder is left.

The bonus version stores the same kind of stash in a linked list. Each node belongs to one file descriptor and is created on first use, so calls for different descriptors keep separate data; a node is removed on EOF, an error, or a failed allocation.

## Resources

- `man 2 read`
- `man 3 malloc`
- The 42 get_next_line subject
- [GeeksforGeeks: Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [GeeksforGeeks: Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/)

AI usage: AI was used to explain concepts, review my code for bugs and memory leaks, and suggest tests. All code was written by me.
