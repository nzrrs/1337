/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:03:30 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/05 14:55:33 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// BASE MACROS
# define BASE10 "0123456789"
# define BASE16MAJ "0123456789ABCDEF"
# define BASE16MIN "0123456789abcdef"

// MAIN FUNCTIONS
int	ft_printf(const char *format, ...);
int	ft_handler(char spec, va_list *ap);
// HELPERS
int	ft_putnbr(int nbr);
int	ft_putbase(unsigned long nb, char *base);
int	ft_putchar(char c);
int	ft_putstr(char *s);
// HANDLERS
int	ft_handle_char(char spec, va_list *ap);
int	ft_handle_x_min(va_list *ap);
int	ft_handle_x_maj(va_list *ap);
int	ft_handle_s(va_list *ap);
int	ft_handle_u(va_list *ap);
int	ft_handle_decimal(va_list *ap);
int	ft_handle_p(va_list *ap);

#endif
