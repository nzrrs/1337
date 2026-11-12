/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 09:55:00 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/12 09:34:28 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(int fd, char *read_buf, char *stash)
{
	ssize_t	bytes_read;
	char	*old;

	bytes_read = 1;
	while (stash && !ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		old = stash;
		stash = ft_strjoin(old, read_buf);
		free(old);
		if (!stash || stash[0] == '\0')
		{
			free(stash);
			return (NULL);
		}
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	line_len;
	char	*line;
	char	*nl;

	nl = ft_strchr(stash, '\n');
	if (nl)
	{
		line_len = (nl - stash) + 1;
		line = ft_substr(stash, 0, line_len);
	}
	else
		line = ft_strdup(stash);
	return (line);
}

static int	trim_stash(char **stash)
{
	char	*old;
	char	*nl;
	char	*new_stash;

	nl = ft_strchr(*stash, '\n');
	if (nl && nl[1] != '\0')
	{
		new_stash = ft_strdup(nl + 1);
		if (!new_stash)
			return (-1);
		old = *stash;
		*stash = new_stash;
		free(old);
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*read_buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	read_buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	stash = fill_stash(fd, read_buf, stash);
	free(read_buf);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (trim_stash(&stash) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
