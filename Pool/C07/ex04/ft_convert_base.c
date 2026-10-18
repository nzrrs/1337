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
#include <stdlib.h>

int		ft_convert_base2(char *str, char *base);
int		ft_check_base(char *base, int *len);

int	ft_determine_size(int nbr, int base_to_len)
{
	int		counter;
	long	n;

	counter = 2;
	n = nbr;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n >= base_to_len)
	{
		n /= base_to_len;
		counter++;
	}
	return (counter);
}

char	*ft_fill_result(int nbr, char *base_to, int base_to_len, int size)
{
	long	n;
	int		i;
	char	*result;
	int		start;

	n = nbr;
	start = 0;
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
		start = 1;
	}
	i = size - 2;
	while (i >= start)
	{
		result[i] = base_to[n % base_to_len];
		n /= base_to_len;
		i--;
	}
	result[size - 1] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_from;
	int		base_from_len;
	int		base_to_len;
	int		size;
	char	*result;

	base_to_len = 0;
	base_from_len = 0;
	if (!((ft_check_base(base_from, &base_from_len)) && ft_check_base(base_to,
				&base_to_len)))
		return (0);
	nb_from = ft_convert_base2(nbr, base_from);
	size = ft_determine_size(nb_from, base_to_len);
	result = ft_fill_result(nb_from, base_to, base_to_len, size);
	if (result == NULL)
		return (NULL);
	return (result);
}
