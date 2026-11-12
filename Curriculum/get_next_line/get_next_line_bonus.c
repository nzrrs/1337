/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:23:38 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/12 09:23:47 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*trim_stash(char *stash)
{
	char	*old;
	char	*nl;

	nl = ft_strchr(stash, '\n');
	if (nl && nl[1] != '\0')
	{
		old = stash;
		stash = ft_strdup(nl + 1);
		free(old);
	}
	else
	{
		free(stash);
		stash = NULL;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*read_buf;

	if ((fd < 0 || fd >= 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	stash[fd] = fill_stash(fd, read_buf, stash[fd]);
	free(read_buf);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = trim_stash(stash[fd]);
	return (line);
}
