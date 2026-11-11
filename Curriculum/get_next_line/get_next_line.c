/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 09:55:01 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/08 11:35:02 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_chunk(int fd, char *buf, char *chunk)
{
	int		readed_size;
	char	*temp;

	readed_size = 1;
	while (!ft_strchr(chunk, '\n') && readed_size > 0)
	{
		readed_size = read(fd, buf, BUFFER_SIZE);
		if (readed_size == -1)
		{
			free(chunk);
			chunk = NULL;
			return (NULL);
		}
		buf[readed_size] = '\0';
		temp = chunk;
		chunk = ft_strjoin(temp, buf);
		free(temp);
		if (!chunk || chunk[0] == '\0')
		{
			free(chunk);
			chunk = NULL;
			return (NULL);
		}
	}
	return (chunk);
}

static char	*ft_get_line(char *chunk)
{
	int		new_line_idx;
	char	*line;
	char	*pos;

	pos = ft_strchr(chunk, '\n');
	if (pos)
	{
		new_line_idx = pos - chunk;
		line = ft_substr(chunk, 0, new_line_idx + 1);
	}
	else
		line = ft_strdup(chunk);
	return (line);
}

static char	*ft_left_over(char *chunk)
{
	char	*temp;
	size_t	new_line_idx;
	char	*pos;

	pos = ft_strchr(chunk, '\n');
	if (pos)
	{
		temp = chunk;
		new_line_idx = pos - chunk;
		chunk = ft_substr(temp, new_line_idx + 1, ft_strlen(chunk));
		free(temp);
	}
	else
	{
		free(chunk);
		chunk = NULL;
	}
	return (chunk);
}

char	*get_next_line(int fd)
{
	static char	*chunk;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!chunk)
		chunk = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	chunk = ft_read_chunk(fd, buf, chunk);
	free(buf);
	if (!chunk)
	{
		return (NULL);
	}
	line = ft_get_line(chunk);
	chunk = ft_left_over(chunk);
	return (line);
}
