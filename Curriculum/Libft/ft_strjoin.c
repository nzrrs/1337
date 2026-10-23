/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:59:33 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/23 13:50:24 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > SIZE_MAX - s2_len - 1)
		return (NULL);
	total = s1_len + s2_len + 1;
	dest = malloc(total);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcat(dest, s2, total);
	return (dest);
}
