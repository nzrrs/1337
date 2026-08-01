/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:58:23 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/30 22:59:58 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(ft_str_len(src) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_str_len(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		if (result[i].copy == NULL)
		{
			while (--i >= 0)
				free(result[i].copy);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[ac].str = 0;
	return (result);
}
