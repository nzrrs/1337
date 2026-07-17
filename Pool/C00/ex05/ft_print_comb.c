/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:51:45 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/16 13:18:25 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_logic(int i, int j, int k)
{
	if (!(i == 7 + '0' && k == 9 + '0'))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		write(1, ", ", 2);
	}
	else
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_logic(i + '0', j + '0', k + '0');
				k++;
			}
			j++;
		}
		i++;
	}
}
