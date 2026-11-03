/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:02:02 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 11:18:01 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_putnbr_base(int nbr, char *base, int *total_printed)
{
	long	nb;
	int		len;

	len = 0;
	nb = nbr;
	if (!(ft_check_base(base, &len)))
		return ;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		(*total_printed)++;
	}
	if (nb >= len)
		ft_putnbr_base((nb / len), base, total_printed);
	ft_putchar(base[nb % len]);
	(*total_printed)++;
}
