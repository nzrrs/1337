/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:03:30 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 10:20:19 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

// To remove later
#include <stdio.h>
//
// MACROS
#define BASE10 "0123456789"
#define BASE16MAJ "0123456789ABCDEF"
#define BASE16MIN "0123456789abcdef"

int	ft_printf(const char *, ...);
int	ft_putnbr_base(int nbr, char *base);
