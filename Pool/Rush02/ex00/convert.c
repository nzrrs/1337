/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:46:45 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:00:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_word(char *str, int *first)
{
	if (!str || !str[0])
		return (0);
	if (!first)
		return (1);
	if (!(*first))
		write(1, " ", 1);
	while (*str)
		write(1, str++, 1);
	*first = 0;
	return (1);
}

int	print_hundreds(char *num, t_dict *dict, int *first)
{
	char	hundred[2];

	if (num[0] == '0')
		return (1);
	hundred[0] = num[0];
	hundred[1] = '\0';
	if (!print_word(ft_get_val(hundred, dict), first))
		return (0);
	return (print_word(ft_get_val("100", dict), first));
}

int	print_over_twenty(char *num, t_dict *dict, int *first)
{
	char	tens[3];
	char	ones[2];

	tens[0] = num[1];
	tens[1] = '0';
	tens[2] = '\0';
	if (!print_word(ft_get_val(tens, dict), first))
		return (0);
	if (num[2] == '0')
		return (1);
	ones[0] = num[2];
	ones[1] = '\0';
	return (print_word(ft_get_val(ones, dict), first));
}

int	print_tens(char *num, t_dict *dict, int *first)
{
	char	small[3];

	if (num[1] >= '2')
		return (print_over_twenty(num, dict, first));
	if (num[1] == '1')
	{
		small[0] = num[1];
		small[1] = num[2];
		small[2] = '\0';
		return (print_word(ft_get_val(small, dict), first));
	}
	if (num[2] == '0')
		return (1);
	small[0] = num[2];
	small[1] = '\0';
	return (print_word(ft_get_val(small, dict), first));
}

int	handle_three(char *num, t_dict *dict, int *first)
{
	if (!print_hundreds(num, dict, first))
		return (0);
	return (print_tens(num, dict, first));
}
