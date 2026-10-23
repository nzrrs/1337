/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:18:21 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/23 13:51:46 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*firsts;
	const unsigned char	*seconds;
	size_t				i;

	i = 0;
	firsts = s1;
	seconds = s2;
	if (n == 0 || firsts == seconds)
		return (0);
	while (i < n)
	{
		if (firsts[i] == seconds[i])
			i++;
		else
			return (firsts[i] - seconds[i]);
	}
	if (i == n)
		return (0);
	return (firsts[i] - seconds[i]);
}
