/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:17:02 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/21 21:17:02 by nsadiki          ###   ########.fr       */
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

void	ft_putnbr_base(int nbr, char *base)
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
	}
	if (nb >= len)
		ft_putnbr_base((nb / len), base);
	ft_putchar(base[nb % len]);
}
