/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:24:42 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:27:36 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handle_char(char spec, va_list *ap)
{
	char	c;

	if (spec == '%')
		c = '%';
	else
		c = va_arg(*ap, int);
	return (write(1, &c, 1));
}
