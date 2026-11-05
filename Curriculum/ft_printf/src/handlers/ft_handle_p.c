/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:37:31 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:44:39 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_p(va_list *ap)
{
	unsigned long	up;
	int				test;

	up = (unsigned long)va_arg(*ap, void *);
	if (!up)
		return (ft_putstr("(nil)"));
	else
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		test = ft_putbase(up, BASE16MIN);
		if (test == -1)
			return (-1);
		return (test + 2);
	}
}
