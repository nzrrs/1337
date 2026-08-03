/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:00:00 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:00:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_file_size(char *filename)
{
	char	c;
	int		fd;
	int		ret;
	int		size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	ret = read(fd, &c, 1);
	while (ret > 0)
	{
		size++;
		ret = read(fd, &c, 1);
	}
	close(fd);
	if (ret < 0)
		return (-1);
	return (size);
}

int	read_file(char *filename, char *buf, int size)
{
	int	fd;
	int	ret;
	int	total;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	total = 0;
	while (total < size)
	{
		ret = read(fd, buf + total, size - total);
		if (ret <= 0)
		{
			close(fd);
			return (0);
		}
		total += ret;
	}
	ret = read(fd, buf + total, 1);
	close(fd);
	if (ret != 0)
		return (0);
	buf[total] = '\0';
	return (1);
}

char	*load_file(char *filename, int *size)
{
	char	*buf;

	*size = get_file_size(filename);
	if (*size < 0)
		return (NULL);
	buf = malloc(*size + 1);
	if (!buf)
		return (NULL);
	if (!read_file(filename, buf, *size))
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
