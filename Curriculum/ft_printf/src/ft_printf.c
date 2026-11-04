/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:18:02 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 21:18:45 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total_printed;
	int		test;
	int		i;
	va_list	ap;

	total_printed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')
			{
				test = ft_putstr(va_arg(ap, char *));
				if (test == -1)
					return (-1);
				total_printed += test;
				i++;
			}
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				test = ft_putnbr(va_arg(ap, int));
				if (test == -1)
					return (-1);
				total_printed += test;
				i++;
			}
			i++;
		}
		else
		{
			test = ft_putchar(format[i]);
			if (test == -1)
				return (-1);
			total_printed += test;
			i++;
		}
	}
	va_end(ap);
	return (total_printed);
}
