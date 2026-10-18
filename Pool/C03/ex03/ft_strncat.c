/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:39:15 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/20 12:39:15 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	start;

	start = 0;
	i = 0;
	while (dest[start] != '\0')
	{
		start++;
	}
	while (src[i] != '\0' && i < nb)
	{
		dest[i + start] = src[i];
		i++;
	}
	dest[i + start] = '\0';
	return (dest);
}
