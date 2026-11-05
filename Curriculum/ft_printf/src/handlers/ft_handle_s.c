/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:35:05 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:37:07 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_s(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}
