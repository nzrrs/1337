/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:04:38 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/28 19:26:57 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_total_len(int size, char **strs, char *sep)
{
	int	strs_len;
	int	sep_len;
	int	i;
	int	j;

	i = 0;
	strs_len = 0;
	sep_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			strs_len++;
			j++;
		}
		i++;
	}
	while (sep[sep_len])
		sep_len++;
	return (strs_len + (sep_len * (size - 1)));
}

void	ft_fill_result(int size, char **strs, char *result, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			result[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;

	if (size == 0)
	{
		result = malloc(1);
		result[0] = '\0';
		return (result);
	}
	total_len = ft_total_len(size, strs, sep);
	result = malloc(total_len + 1);
	ft_fill_result(size, strs, result, sep);
	return (result);
}
