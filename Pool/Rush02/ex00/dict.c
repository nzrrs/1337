/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:19 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:00:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*build_dict(char *buf, int count)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict) * (count + 1));
	if (!dict)
		return (NULL);
	if (!fill_dict(dict, buf))
	{
		free_dict(dict);
		return (NULL);
	}
	return (dict);
}

t_dict	*parse_dict(char *filename)
{
	char	*buf;
	t_dict	*dict;
	int		count;
	int		size;

	buf = load_file(filename, &size);
	if (!buf)
		return (NULL);
	count = count_entries(buf);
	if (ft_strlen(buf) != size || count <= 0)
	{
		free(buf);
		return (NULL);
	}
	dict = build_dict(buf, count);
	free(buf);
	return (dict);
}

char	*ft_get_val(char *str, t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].key)
	{
		j = 0;
		while (str[j] && dict[i].key[j] && str[j] == dict[i].key[j])
			j++;
		if (!str[j] && !dict[i].key[j])
			return (dict[i].val);
		i++;
	}
	return (NULL);
}

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (dict[i].key)
	{
		free(dict[i].key);
		free(dict[i].val);
		i++;
	}
	free(dict);
}
