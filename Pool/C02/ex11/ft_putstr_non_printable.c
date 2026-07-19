/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:25:13 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/19 17:30:55 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	c;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c <= 31 || c == 127)
		{
			ft_putchar('\\');
			ft_putchar(hex[c / 16]);
			ft_putchar(hex[c % 16]);
		}
		else
		{
			ft_putchar(c);
		}
		i++;
	}
}
