/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 08:46:48 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/17 09:06:55 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	first_index;
	int	last_index;
	int	temp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		first_index = i;
		last_index = (size - 1) - i;
		temp = tab[first_index];
		tab[first_index] = tab[last_index];
		tab[last_index] = temp;
		i++;
	}
}
