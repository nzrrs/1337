/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:03:30 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/03 13:25:49 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

// MACROS
#define BASE10 "0123456789"
#define BASE16MAJ "0123456789ABCDEF"
#define BASE16MIN "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putnbr(int nbr);
int	ft_putbase(unsigned long nb, char *base);
int	ft_putchar(char c);
int	ft_putstr(char *s);
