/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:55:14 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:55:21 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_x_min(va_list *ap)
{
	unsigned int	x;

	x = va_arg(*ap, int);
	return (ft_putbase(x, BASE16MIN));
}
