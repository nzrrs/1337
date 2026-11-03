/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:37:05 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 13:49:55 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_dispatcher(char specifier, va_list *list)
{
	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(*list, int), 1));
	else if (specifier == 's')
		return (ft_putstr_fd(va_arg(*list, char *), 1));
	else if (specifier == 'd')
		return (ft_putnbr_base(va_arg(*list, int), BASE10));
	else if (specifier == 'p')
		return (0);
}
