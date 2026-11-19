/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:42:38 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:43:36 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handle_decimal(va_list *ap)
{
	int	nb;

	nb = va_arg(*ap, int);
	return (ft_putnbr(nb));
}
