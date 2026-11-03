/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:18:37 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 13:48:48 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		total_printed;
	int		i;
	int		result;

	va_start(list, format);
	i = 0;
	total_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			result = ft_dispatcher(format[i + 1], &list);
			i += 2;
		}
		else
		{
			result = ft_putchar_fd(format[i], 1);
			i++;
		}
		if (result < 0)
			return (-1);
		total_printed += result;
	}
	va_end(list);
	return (total_printed);
}

int	main(void)
{
	int	total_printed_mine;
	int	total_printed_original;

	total_printed_mine = ft_printf("Number : %d\nString : %s\nChar : %c\n", 5,
			"Hello", 'a');
	printf("total_printed_mine=> %d\n", total_printed_mine);
	printf("============================================\n");
	total_printed_original = printf("Number : %d\nString : %s\nChar : %c\n", 5,
			"Hello", 'a');
	printf("total_printed_original=> %d\n", total_printed_original);
	return (0);
}
