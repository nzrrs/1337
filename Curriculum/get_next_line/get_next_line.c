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

static char	*free_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}

static char	*fill_stash(int fd, char *read_buf, char *stash)
{
	ssize_t	bytes_read;
	char	*old;

	bytes_read = 1;
	while (stash && !ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_stash(&stash));
		if (bytes_read == 0)
			break ;
		read_buf[bytes_read] = '\0';
		old = stash;
		stash = ft_strjoin(stash, read_buf);
		free(old);
		if (!stash)
			return (free_stash(&stash));
	}
	if (!stash || !stash[0])
		return (free_stash(&stash));
	return (stash);
}

static char	*extract_and_trim(char **stash)
{
	char	*nl;
	char	*old;
	char	*line;

	nl = ft_strchr(*stash, '\n');
	if (nl)
		line = ft_substr(*stash, 0, (nl - *stash) + 1);
	else
		line = ft_strdup(*stash);
	if (line && nl && nl[1])
	{
		old = *stash;
		*stash = ft_strdup(nl + 1);
		free(old);
		if (!*stash)
		{
			free(line);
			return (NULL);
		}
	}
	else
		free_stash(stash);
	return (line);
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
	read_buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!read_buf)
		return (free_stash(&stash));
	stash = fill_stash(fd, read_buf, stash);
	free(read_buf);
	if (!stash)
		return (NULL);
	line = extract_and_trim(&stash);
	return (line);
}
