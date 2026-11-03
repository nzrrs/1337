/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:18:37 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 11:24:17 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_dispatch(char specifier, va_list *args, int *total);
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
				ft_putnbr_base(va_arg(list, int), BASE10, &total_printed);
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

	a = ft_printf("Total : %zu\n", sizeof(va_list));
	printf("a => %d\n", a);
	// printf("Total : %d\n", 5);
	return (0);
}
