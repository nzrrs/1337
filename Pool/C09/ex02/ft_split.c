/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:33:25 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/02 23:32:00 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_sep(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_count_words(char *str, char *sep)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (!(ft_is_sep(sep, str[i])) && (i == 0 || ft_is_sep(sep, str[i - 1])))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		size;
	int		i;
	int		k;
	int		j;
	char	*word;

	size = ft_count_words(str, charset);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!(ft_is_sep(charset, str[i])) && (i == 0 || ft_is_sep(charset, str[i
					- 1])))
		{
			j = 0;
			word = malloc(ft_count_words(str, charset) + 1);
			while (str[i] && ft_is_sep(charset, str[i + 1]))
			{
				word[j] = str[i];
				i++;
				j++;
			}
			word[j] = '\0';
			result[k] = word;
			k++;
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("Hello,,world;42;Piscine", ",;");
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("result[%d] = \"%s\"\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
