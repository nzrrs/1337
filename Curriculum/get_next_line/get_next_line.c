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
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*chunk;
	char		*buf;
	int			readed_size;
	int			new_line_idx;
	char		*result;

	// init
	readed_size = 0;
	// if chunk is null
	if (!chunk)
		chunk = ft_strdup("");
	result = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	// check guards
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// first read
	readed_size = read(fd, buf, BUFFER_SIZE);
	// check read
	if (readed_size == -1)
		return (NULL);
	buf[readed_size] = '\0';
	// append buf to chunk;
	chunk = ft_strjoin(chunk, buf);
	if (chunk[0] == '\0')
	{
		free(chunk);
		chunk = NULL;
		return (NULL);
	}
	// if chunk still dont have new line re-read and append
	while (!ft_strchr(chunk, '\n') && readed_size > 0)
	{
		readed_size = read(fd, buf, BUFFER_SIZE);
		if (readed_size == -1)
		{
			free(buf);
			free(chunk);
			return (NULL);
		}
		buf[readed_size] = '\0';
		chunk = ft_strjoin(chunk, buf);
	}
	// if chunk now have new line
	if (ft_strchr(chunk, '\n'))
	{
		new_line_idx = (ft_strchr(chunk, '\n') - chunk);
		result = ft_substr(chunk, 0, new_line_idx + 1);
		chunk = ft_substr(chunk, new_line_idx + 1, ft_strlen(chunk));
	}
	else if (!ft_strchr(chunk, '\n') && readed_size == 0)
	{
		result = ft_strdup(chunk);
		free(chunk);
		chunk = NULL;
		return (result);
	}
	else if (readed_size == -1)
		return (NULL);
	return (result);
}
