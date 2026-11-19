/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:18:07 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/23 13:52:39 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(int n)
{
	int		digits;
	long	num;

	num = n;
	digits = 1;
	while (num < 0)
	{
		digits++;
		num *= -1;
	}
	while (num >= 10)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int i)
{
	char	*res;
	int		size;
	long	value;

	value = i;
	size = ft_count(value) + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	if (value < 0)
	{
		res[0] = '-';
		value *= -1;
	}
	res[--size] = '\0';
	while (value >= 10)
	{
		res[--size] = value % 10 + '0';
		value /= 10;
	}
	res[--size] = value + '0';
	return (res);
}
