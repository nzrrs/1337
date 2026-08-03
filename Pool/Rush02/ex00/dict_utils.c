/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:35 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:00:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*copy_part(char *buf, int start, int end)
{
	char	*res;
	int		i;

	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = buf[start++];
	res[i] = '\0';
	return (res);
}

int	add_entry(t_dict *dict, char *buf, t_line *part, int line)
{
	dict[line].key = copy_part(buf, part->key_start, part->key_end);
	if (!dict[line].key)
		return (0);
	dict[line].val = copy_part(buf, part->val_start, part->val_end);
	if (!dict[line].val)
	{
		free(dict[line].key);
		dict[line].key = NULL;
		return (0);
	}
	return (1);
}

int	fill_dict(t_dict *dict, char *buf)
{
	t_line	part;
	int		i;
	int		line;
	int		status;

	i = 0;
	line = 0;
	dict[0].key = NULL;
	dict[0].val = NULL;
	while (buf[i])
	{
		status = parse_line(buf, &i, &part);
		if (status < 0)
			return (0);
		if (status == 1)
		{
			if (!add_entry(dict, buf, &part, line))
				return (0);
			line++;
			dict[line].key = NULL;
			dict[line].val = NULL;
		}
	}
	return (1);
}
