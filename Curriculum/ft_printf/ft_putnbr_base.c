/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:24:39 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 13:24:42 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	(write(1, &c, 1));
}

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

void	ft_putnbr_base_recursive(int nbr, int base_len, char *base)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= base_len)
		ft_putnbr_base_recursive((nb / base_len), base_len, base);
	ft_putchar(base[nb % base_len]);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		nbr_len;
	int		base_len;
	long	nb;

	base_len = 0;
	nbr_len = 1;
	nb = nbr;
	if (!(ft_check_base(base, &base_len)))
		return (-1);
	if (nb < 0)
	{
		nb *= -1;
		nbr_len++;
	}
	while (nb >= base_len)
	{
		nb /= base_len;
		nbr_len++;
	}
	ft_putnbr_base_recursive(nbr, base_len, base);
	return (nbr_len);
}
