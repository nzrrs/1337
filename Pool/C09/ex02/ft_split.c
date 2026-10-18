/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:33:25 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/03 17:25:15 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_word_len(char *str, char *sep)
{
	int	len;

	len = 0;
	while (str[len] && !ft_is_sep(sep, str[len]))
		len++;
	return (len);
}

char	*copy_word(char *str, char *charset, int *i)
{
	int		j;
	char	*word;

	j = 0;
	word = malloc(ft_word_len(&str[*i], charset) + 1);
	if (!word)
		return (NULL);
	while (str[*i] && !ft_is_sep(charset, str[*i]))
	{
		word[j] = str[*i];
		(*i)++;
		j++;
	}
	word[j] = '\0';
	return (word);
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
	int		i;
	int		k;

	result = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!(ft_is_sep(charset, str[i]))
			&& (i == 0 || ft_is_sep(charset, str[i - 1])))
		{
			result[k] = copy_word(str, charset, &i);
			k++;
		}
		i++;
	}
	result[k] = NULL;
	return (result);
}
