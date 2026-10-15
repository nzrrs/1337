/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:01:57 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/14 21:27:38 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		if (result > (9223372036854775807 - (*nptr - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
