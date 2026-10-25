/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:05:56 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/23 13:52:56 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*p;
	size_t			total;

	if (n != 0 && size > SIZE_MAX / n)
		return (NULL);
	total = n * size;
	if (total == 0)
	{
		p = malloc(1);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
