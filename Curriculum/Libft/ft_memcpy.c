/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:47:54 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/23 13:51:41 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*b;

	p = dest;
	b = src;
	i = 0;
	if (!p && !b)
		return (NULL);
	while (i < n)
	{
		p[i] = b[i];
		i++;
	}
	return (dest);
}
