/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:19:14 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/22 12:42:16 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_sign(char *str, int *sign, char *base)
{
	while ((*str >= 9 && *str <= 32) || *str == ' ')
		str++;
	while (*str && ft_index(*str, base) == -1)
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				*sign *= -1;
		}
		else
			return (0);
		str++;
	}
	return (str);
}

int	ft_calcul(char *str, char *base, int *len)
{
	int	digit;
	int	result;

	result = 0;
	while (*str && ft_index(*str, base) != -1)
	{
		digit = ft_index(*str, base);
		result = result * (*len) + digit;
		str++;
	}
	return (result);
}

int	ft_check_base(char *base, int *len)
{
	int	j;
	int	i;

	while (base[*len])
	{
		if (base[*len] == '+' || base[*len] == '-' || (base[*len] >= 9
				&& base[*len] <= 32) || base[*len] == ' ')
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

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	len;
	int	result;

	sign = 1;
	len = 0;
	if (!ft_check_base(base, &len))
	{
		return (0);
	}
	str = ft_sign(str, &sign, base);
	result = ft_calcul(str, base, &len);
	return (result * sign);
}
