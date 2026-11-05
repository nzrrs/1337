/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:54:57 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:56:50 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_x_maj(va_list *ap)
{
	unsigned int	x;

	x = va_arg(*ap, int);
	return (ft_putbase(x, BASE16MAJ));
}
