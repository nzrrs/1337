/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:18:07 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/20 09:36:58 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_len(int nbr)
{
	int	len;

	len = 1;
	while (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int i)
{
	char	*str;
	int		len;

	len = ft_get_len(i) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	len--;
	str[len] = '\0';
	while (i >= 10)
	{
		len--;
		str[len] = i % 10 + '0';
		i = i / 10;
	}
	str[len - 1] = i + '0';
	return (str);
}
