/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:21:43 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/06 18:44:21 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_skip_sign(char *str, int *sign)
{
	while (*str && *str >= 9 && *str <= 32)
	{
		str++;
	}
	while (*str > '9' || *str < '0')
	{
		if (*str == '-' || *str == '+')
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

int	ft_calcul(char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result);
}
int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	sign = 1;
	str = ft_skip_sign(str, &sign);
	if (str == 0)
		return (0);
	result = ft_calcul(str);
	return (result * sign);
}

int	main(void)
{
	char	*str;

	str = "3";
	printf("%d\n", ft_atoi(str));
}
