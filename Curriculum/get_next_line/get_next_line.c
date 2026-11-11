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
	char		*temp;

	readed_size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!chunk)
		chunk = ft_strdup("");
	while (!ft_strchr(chunk, '\n') && readed_size > 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		readed_size = read(fd, buf, BUFFER_SIZE);
		if (readed_size == -1)
		{
			free(buf);
			free(chunk);
			return (NULL);
		}
		buf[readed_size] = '\0';
		temp = chunk;
		chunk = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
		if (!chunk || chunk[0] == '\0')
		{
			free(chunk);
			return (NULL);
		}
	}
	if (ft_strchr(chunk, '\n') && readed_size >= 0)
	{
		temp = chunk;
		new_line_idx = (ft_strchr(chunk, '\n') - chunk);
		result = ft_substr(temp, 0, new_line_idx + 1);
		chunk = ft_substr(temp, new_line_idx + 1, ft_strlen(chunk));
		free(temp);
	}
	else if (!ft_strchr(chunk, '\n') && readed_size >= 0)
	{
		result = ft_strdup(chunk);
		free(chunk);
	}
	else if (readed_size == -1)
	{
		free(chunk);
		free(buf);
		return (NULL);
	}
	return (result);
}
