/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:31:40 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:34:51 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_u(va_list *ap)
{
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	return (ft_putbase(u, BASE10));
}
