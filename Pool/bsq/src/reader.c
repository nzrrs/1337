#include "bsq.h"

static char	*read_fd(int fd)
{
	char	*buf;
	char	*tmp;
	char	chunk[4096];
	ssize_t	r;
	size_t	len;

	len = 0;
	buf = ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	r = read(fd, chunk, sizeof(chunk));
	while (r > 0)
	{
		tmp = malloc(len + (size_t)r + 1);
		if (!tmp)
		{
			free(buf);
			return (NULL);
		}
		memcpy(tmp, buf, len);
		memcpy(tmp + len, chunk, (size_t)r);
		len += (size_t)r;
		tmp[len] = '\0';
		free(buf);
		buf = tmp;
		r = read(fd, chunk, sizeof(chunk));
	}
	if (r < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*read_file(const char *path)
{
	int		fd;
	char	*content;

	if (!path)
		return (read_fd(0));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_fd(fd);
	close(fd);
	return (content);
}

char	**split_lines(const char *content, int *line_count)
{
	int		i;
	int		start;
	int		total;
	int		count;
	char	**lines;

	total = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			total++;
		i++;
	}
	if (i > 0 && content[i - 1] != '\n')
		total++;
	lines = malloc(sizeof(char *) * (total + 1));
	if (!lines)
		return (NULL);
	i = 0;
	start = 0;
	count = 0;
	while (1)
	{
		if (content[i] == '\n' || content[i] == '\0')
		{
			if (i - start > 0 || content[i] == '\n')
			{
				lines[count] = malloc((i - start) + 1);
				if (!lines[count])
					return (NULL);
				memcpy(lines[count], content + start, i - start);
				lines[count][i - start] = '\0';
				count++;
			}
			start = i + 1;
			if (content[i] == '\0')
				break ;
		}
		i++;
	}
	lines[count] = NULL;
	*line_count = count;
	return (lines);
}
