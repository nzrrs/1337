/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:21:03 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:00:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_magnitude(char *key, int zeros)
{
	int	i;

	if (key[0] != '1' || ft_strlen(key) != zeros + 1)
		return (0);
	i = 1;
	while (key[i])
	{
		if (key[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*get_magnitude(int zeros, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		if (is_magnitude(dict[i].key, zeros))
			return (dict[i].val);
		i++;
	}
	return (NULL);
}

char	*pad_number(char *num, int *total)
{
	char	*tmp;
	int		len;
	int		pad;
	int		i;

	len = ft_strlen(num);
	pad = (3 - (len % 3)) % 3;
	*total = len + pad;
	tmp = malloc(*total + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < pad)
		tmp[i++] = '0';
	while (*num)
		tmp[i++] = *num++;
	tmp[i] = '\0';
	return (tmp);
}

int	convert_chunks(char *tmp, int total, t_dict *dict, int *first)
{
	char	*word;
	int		i;
	int		value;
	int		remaining;

	i = 0;
	while (i < total)
	{
		value = (tmp[i] - '0') * 100;
		value += (tmp[i + 1] - '0') * 10 + tmp[i + 2] - '0';
		if (value && !handle_three(tmp + i, dict, first))
			return (0);
		remaining = total - i - 3;
		if (value && remaining)
		{
			word = get_magnitude(remaining, dict);
			if (!print_word(word, first))
				return (0);
		}
		i += 3;
	}
	return (1);
}

int	ft_convert(char *num, t_dict *dict, int *first)
{
	char	*tmp;
	int		total;
	int		i;

	i = 0;
	while (num[i] == '0')
		i++;
	if (!num[i])
		return (print_word(ft_get_val("0", dict), first));
	tmp = pad_number(num, &total);
	if (!tmp)
		return (0);
	if (!convert_chunks(tmp, total, dict, NULL))
	{
		free(tmp);
		return (0);
	}
	convert_chunks(tmp, total, dict, first);
	free(tmp);
	return (1);
}
