/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:02:33 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/17 12:14:43 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	const unsigned char *p;

	p = s;

	while (n--)
	{
		if (*p == (unsigned char)c)
			return (void *)(p);

		p++;
	}
	return (NULL);
}
