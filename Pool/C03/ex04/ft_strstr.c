/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:26:23 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/20 16:16:50 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

	if (!(*to_find))
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			s = str;
			f = to_find;
			while (*s == *f && *f != '\0')
			{
				s++;
				f++;
			}
			if (*f == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
