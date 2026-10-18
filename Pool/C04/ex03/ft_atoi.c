/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:47:46 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/21 21:08:41 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_skip(char *str)
{
	while ((*str >= 9 && *str <= 32) || *str == ' ')
		str++;
	return (str);
}

char	*ft_sign(char *str, int *sign)
{
	while (*str && !(*str >= '0' && *str <= '9'))
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

int	ft_calcul(char *str)
{
	int	digit;
	int	result;

	result = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	str = ft_skip(str);
	str = ft_sign(str, &sign);
	if (str == 0)
	{
		return (0);
	}
	result = ft_calcul(str);
	return (result * sign);
}
