/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:50:13 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/19 22:22:25 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || (i != 0 && s[i - 1] == c)))
			counter++;
		i++;
	}
	return (counter);
}

static int	ft_word_len(char const *s, int start, char c)
{
	int	word_len;

	word_len = 0;
	while (s[start])
	{
		if (s[start] == c)
			return (word_len);
		word_len++;
		start++;
	}
	return (word_len);
}

static void	*free_words(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**ft_arr_fill(char const *s, char **arr, size_t arr_len, char c)
{
	size_t	s_i;
	size_t	arr_i;
	size_t	word_len;

	s_i = 0;
	arr_i = 0;
	while (s[s_i])
	{
		if (s[s_i] != c && (s_i == 0 || s[s_i - 1] == c))
		{
			word_len = ft_word_len(s, s_i, c);
			arr[arr_i] = ft_substr(s, s_i, word_len);
			if (arr[arr_i] == NULL)
				return (free_words(arr, arr_len));
			arr_i++;
			s_i += word_len;
		}
		else
			s_i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_len;

	if (!s)
		return (NULL);
	arr_len = ft_count_words(s, c);
	arr = ft_calloc(arr_len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_arr_fill(s, arr, arr_len, c));
}
