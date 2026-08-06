/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:00:00 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/06 05:00:05 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		left;
	int		right;
	int		size;

	size = 0;
	left = 0;
	while (tab[size])
		size++;
	while (left < size)
	{
		right = left + 1;
		while (right < size)
		{
			if (cmp(tab[left], tab[right]) > 0)
			{
				temp = tab[left];
				tab[left] = tab[right];
				tab[right] = temp;
			}
			right++;
		}
		left++;
	}
}
