/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:05:52 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/29 16:51:38 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_base(char *base, int *len)
{
	int	i;
	int	j;

	i = 0;
	while (base[*len] != '\0')
	{
		if (base[*len] == '+' || base[*len] == '-' || ((base[*len] >= 9
					&& base[*len] <= 32) || base[*len] == ' '))
			return (0);
		(*len)++;
	}
	if (*len < 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (*len);
}

int	ft_get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_skip_and_sign(char *str, int *sign, char *base)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (ft_get_index(*str, base) == -1)
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				*sign *= -1;
			str++;
		}
		else
			return (0);
	}
	return (str);
}

int	ft_calcul(char *str, char *base, int len)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (ft_get_index(str[i], base) != -1)
	{
		result = (result * len) + ft_get_index(str[i], base);
		i++;
	}
	return (result);
}

int	ft_convert_base2(char *str, char *base_from)
{
	int	sign;
	int	len;
	int	result;

	sign = 1;
	len = 0;
	if (!ft_check_base(base_from, &len))
		return (0);
	printf("%d", len);
	str = ft_skip_and_sign(str, &sign, base_from);
	if (!str)
		return (0);
	result = ft_calcul(str, base_from, len);
	return (result * sign);
}
