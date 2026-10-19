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

static int	ft_is_sep(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int	ft_count_words(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_is_sep(s[i], c) && (i == 0 || (i != 0 && ft_is_sep(s[i - 1],
						c))))
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
		if (ft_is_sep(s[start], c))
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

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_len;
	size_t	arr_i;
	size_t	word_len;
	size_t	s_i;

	arr_i = 0;
	s_i = 0;
	arr_len = ft_count_words(s, c);
	arr = ft_calloc(arr_len + 1, sizeof(char *));
	if (!arr)
		free_words(arr, arr_len);
	while (s[s_i])
	{
		if (!(ft_is_sep(s[s_i], c)) && (s_i == 0 || (s_i != 0 && ft_is_sep(s[s_i
							- 1], c))))
		{
			word_len = ft_word_len(s, s_i, c);
			arr[arr_i] = ft_substr(s, s_i, word_len);
			if (arr[arr_i] == NULL)
				free_words(arr, arr_len);
			arr_i++;
			s_i += word_len;
		}
		else
			s_i++;
	}
	return (arr);
}

// word is a sequence of non sep chars
// int	main(void)
// {
// 	char const	*s;
// 	char		c;
// 	char		**array;
// 	int			i;
//
// 	s = ";Hello;World;;";
// 	c = ';';
// 	array = ft_split(s, c);
// 	printf("String : %s ", s);
// 	printf("+++++++++++++++\n");
// 	i = 0;
// 	if (!array)
// 		return (1);
// 	while (array[i])
// 	{
// 		printf("[%d] : %s\n", i, array[i]);
// 		i++;
// 	}
// 	printf("[%d] %s\n", i, array[i] ? "NOT NULL (bug)" : "NULL (ok)");
// 	return (0);
// }
