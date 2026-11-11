#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	return (0);
}
