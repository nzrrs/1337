/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:03:37 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/27 21:23:42 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr_ints;
	int	j;

	i = min;
	j = 0;
	if (min >= max)
		return (NULL);
	arr_ints = malloc(sizeof(int) * (max - min));
	if (arr_ints == NULL)
		return (NULL);
	while (i < max)
	{
		arr_ints[j] = i;
		i++;
		j++;
	}
	return (arr_ints);
}
