/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:17:35 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 22:19:30 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_check_base(char *base, int *len)
{
	int	j;
	int	i;

	while (base[*len])
	{
		if (base[*len] == '+' || base[*len] == '-')
			return (0);
		(*len)++;
	}
	if (*len <= 1)
		return (0);
	i = 0;
	while (i < *len - 1)
	{
		j = i + 1;
		while (j < *len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putbase_recursive(unsigned long nb, int base_len, char *base)
{
	int	count;

	count = 0;
	if (nb >= (unsigned long)base_len)
	{
		count = ft_putbase_recursive((nb / base_len), base_len, base);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(base[nb % base_len]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putbase(unsigned long nb, char *base)
{
	int	base_len;

	base_len = 0;
	if (!(ft_check_base(base, &base_len)))
		return (-1);
	return (ft_putbase_recursive(nb, base_len, base));
}
