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
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int				total_printed;
	int				test;
	int				i;
	va_list			ap;
	unsigned long	up;
	char			*s;

	total_printed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			if (format[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				if (s == NULL)
				{
					test = ft_putstr("(null)");
					if (test == -1)
						return (-1);
					total_printed += test;
					i += 2;
				}
				else
				{
					test = ft_putstr(s);
					if (test == -1)
						return (-1);
					total_printed += test;
					i += 2;
				}
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				test = ft_putnbr(va_arg(ap, int));
				if (test == -1)
					return (-1);
				total_printed += test;
				i += 2;
			}
			else if (format[i + 1] == '%')
			{
				test = ft_putchar('%');
				if (test == -1)
					return (-1);
				total_printed += test;
				i += 2;
			}
			else if (format[i + 1] == 'c')
			{
				test = ft_putchar(va_arg(ap, int));
				if (test == -1)
					return (-1);
				total_printed += test;
				i += 2;
			}
			else if (format[i + 1] == 'u')
			{
				test = ft_putbase(va_arg(ap, unsigned int), BASE10);
				if (test == -1)
					return (-1);
				total_printed += test;
				i += 2;
			}
			else if (format[i + 1] == 'x')
			{
				test = ft_putbase((unsigned int)va_arg(ap, int), BASE16MIN);
				if (test == -1)
					return (-1);
				total_printed += test;
				i += 2;
			}
			else if (format[i + 1] == 'X')
			{
				test = ft_putbase((unsigned int)va_arg(ap, int), BASE16MAJ);
				if (test == -1)
					return (-1);
				total_printed += test;
				i += 2;
			}
			else if (format[i + 1] == 'p')
			{
				up = (unsigned long)va_arg(ap, void *);
				if (!up)
				{
					test = ft_putstr("(nil)");
					if (test == -1)
						return (-1);
					total_printed += test;
					i += 2;
				}
				else
				{
					if (write(1, "0x", 2) == -1)
						return (-1);
					test = ft_putbase(up, BASE16MIN);
					if (test == -1)
						return (-1);
					total_printed += test + 2;
					i += 2;
				}
			}
			else
				return (-1);
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
