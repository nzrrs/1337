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

static char	*fill_stash(int fd, char *read_buf, char *stash)
{
	int		bytes_read;
	char	*old;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		old = stash;
		stash = ft_strjoin(old, read_buf);
		free(old);
		if (!stash || stash[0] == '\0')
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		line_len;
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
	if (nl)
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
	static char	*stash;
	char		*line;
	char		*read_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	stash = fill_stash(fd, read_buf, stash);
	free(read_buf);
	if (!stash)
	{
		return (NULL);
	}
	line = extract_line(stash);
	stash = trim_stash(stash);
	return (line);
}
