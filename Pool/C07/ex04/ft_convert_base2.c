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

int	ft_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_sign_and_skip(char *str, char *base, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (ft_index(base, *str) == -1)
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
	int	digit;

	result = 0;
	i = 0;
	while (ft_index(base, str[i]) != -1)
	{
		digit = ft_index(base, str[i]);
		result = result * len + (digit);
		i++;
	}
	return (result);
}

int	ft_check_base(char *base, int *len)
{
	int	i;
	int	j;

	i = 0;
	while (base[*len] != '\0')
	{
		if (base[*len] == '+' || base[*len] == '-' || ((base[*len] >= 9
					&& base[*len] <= 32)))
			return (0);
		(*len)++;
	}
	if (*len <= 1)
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

int	ft_convert_base2(char *str, char *base)
{
	int	sign;
	int	len;
	int	result;

	sign = 1;
	len = 0;
	if (!ft_check_base(base, &len))
		return (0);
	str = ft_sign_and_skip(str, base, &sign);
	if (str == 0)
		return (0);
	result = ft_calcul(str, base, len);
	return (result * sign);
}
