/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:17:07 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:55:44 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler(char spec, va_list *ap)
{
	if (spec == 's')
		return (ft_handle_s(ap));
	else if (spec == 'd' || spec == 'i')
		return (ft_handle_decimal(ap));
	else if (spec == '%' || spec == 'c')
		return (ft_handle_char(spec, ap));
	else if (spec == 'u')
		return (ft_handle_u(ap));
	else if (spec == 'x')
		return (ft_handle_x_min(ap));
	else if (spec == 'X')
		return (ft_handle_x_maj(ap));
	else if (spec == 'p')
		return (ft_handle_p(ap));
	return (-1);
}
