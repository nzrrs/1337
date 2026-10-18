/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 21:39:38 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/20 12:38:43 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (dest[start] != '\0')
	{
		start++;
	}
	while (src[i] != '\0')
	{
		dest[i + start] = src[i];
		i++;
	}
	dest[i + start] = '\0';
	return (dest);
}
