/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:58:08 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/29 20:15:53 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_convert_base2(char *str, char *base_from);
int		ft_check_base(char *base, int *len);

void	ft_count_recursive(int nb, int base_len, int *counter)
{
	if (nb >= base_len)
	{
		ft_count_recursive((nb / base_len), base_len, counter);
	}
	(*counter)++;
	return ;
}
int	ft_count_size(int nbr, int base_len)
{
	int		counter;
	long	nb;

	counter = 0;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		counter = 1;
	}
	ft_count_recursive(nb, base_len, &counter);
	return (counter);
}
char	*put_nbr_base(int nbr, char *base, int base_len, char *result)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= base_len)
		result = put_nbr_base((nb / base_len), base, base_len, result);
	*result = base[nb % base_len];
	result++;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	char	*start;
	int		nbr_base1;
	int		base_from_len;
	int		base_to_len;
	int		size;

	if (!(ft_check_base(base_from, &base_from_len) && ft_check_base(base_to,
				&base_to_len)))
		return (0);
	nbr_base1 = ft_convert_base2(nbr, base_from);
	size = ft_count_size(nbr_base1, base_to_len);
	result = malloc(size + 1);
	if (!result)
		return (0);
	start = result;
	if (nbr_base1 < 0)
	{
		*result = '-';
		result++;
	}
	result = put_nbr_base(nbr_base1, base_to, base_to_len, result);
	*result = '\0';
	return (start);
}
