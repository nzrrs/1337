/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:37:01 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 21:56:43 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_putnbr_recursive(int nbr)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr_recursive((nb / 10));
	ft_putchar(nb % 10);
}

int	ft_putnbr(int nbr)
{
	int		nbr_len;
	long	nb;

	nbr_len = 1;
	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		nbr_len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		nbr_len++;
	}
	ft_putnbr_recursive(nbr);
	return (nbr_len);
}
