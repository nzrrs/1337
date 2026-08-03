/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:00:00 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:00:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_value(char *buf, int *i, t_line *part)
{
	while (buf[*i] == ' ')
		(*i)++;
	part->val_start = *i;
	part->val_end = *i;
	while (buf[*i] && buf[*i] != '\n')
	{
		if (buf[*i] < ' ' || buf[*i] > '~')
			return (0);
		if (buf[*i] != ' ')
			part->val_end = *i + 1;
		(*i)++;
	}
	if (buf[*i] != '\n' || part->val_end == part->val_start)
		return (0);
	(*i)++;
	return (1);
}

int	parse_line(char *buf, int *i, t_line *part)
{
	if (buf[*i] == '\n')
	{
		(*i)++;
		return (0);
	}
	if (buf[*i] < '0' || buf[*i] > '9')
		return (-1);
	part->key_start = *i;
	while (buf[*i] >= '0' && buf[*i] <= '9')
		(*i)++;
	part->key_end = *i;
	while (buf[*i] == ' ')
		(*i)++;
	if (buf[*i] != ':')
		return (-1);
	(*i)++;
	if (!parse_value(buf, i, part))
		return (-1);
	return (1);
}

int	count_entries(char *buf)
{
	t_line	part;
	int		i;
	int		count;
	int		status;

	i = 0;
	count = 0;
	while (buf[i])
	{
		status = parse_line(buf, &i, &part);
		if (status < 0)
			return (-1);
		count += status;
	}
	return (count);
}
