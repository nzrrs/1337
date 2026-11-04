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

int	ft_putnbr(int nbr)
{
	long	nb;
	int		count;
	int		test;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
	}
	if (nb >= 10)
	{
		test = ft_putnbr(nb / 10);
		if (test == -1)
			return (-1);
		count += test;
	}
	if (ft_putchar(nb % 10 + '0') == -1)
		return (-1);
	return (count);
}
