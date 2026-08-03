/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:54:52 by kcherkao          #+#    #+#             */
/*   Updated: 2026/08/02 18:54:56 by kcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*grow_line(char *line, int length, int *capacity)
{
	char	*new_line;
	int		i;

	new_line = malloc(*capacity * 2);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	*capacity *= 2;
	return (new_line);
}

char	*read_number_line(int *status)
{
	char	*line;
	char	c;
	int		capacity;
	int		length;
	int		ret;

	capacity = 16;
	length = 0;
	line = malloc(capacity);
	if (!line)
		return (NULL);
	ret = read(0, &c, 1);
	while (ret > 0 && c != '\n')
	{
		if (length + 1 >= capacity)
			line = grow_line(line, length, &capacity);
		if (!line)
			return (NULL);
		line[length++] = c;
		ret = read(0, &c, 1);
	}
	line[length] = '\0';
	*status = ret;
	return (line);
}

int	print_number(char *num, t_dict *dict)
{
	int	first;

	if (!is_valid_number(num))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	first = 1;
	if (!ft_convert(num, dict, &first))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	write(1, "\n", 1);
	return (1);
}

int	read_stdin(t_dict *dict)
{
	char	*num;
	int		status;

	status = 1;
	while (status > 0)
	{
		num = read_number_line(&status);
		if (!num)
			return (0);
		if (status > 0 || num[0])
		{
			if (!print_number(num, dict))
			{
				free(num);
				return (0);
			}
		}
		free(num);
	}
	return (1);
}
