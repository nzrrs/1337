/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:18:37 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 10:48:12 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		total_printed;
	int		i;

	va_start(list, format);
	i = 0;
	total_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
			{
				total_printed += ft_putnbr_base(va_arg(list, int), BASE10);
				i++;
			}
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 0);
			i++;
			total_printed++;
		}
	}
	va_end(list);
	return (total_printed);
}

int	main(void)
{
	int	a;

	a = ft_printf("Total : %d\n", 5);
	printf("a => %d\n", a);
	// printf("Total : %d\n", 5);
	return (0);
}
