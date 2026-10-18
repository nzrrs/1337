/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 22:41:02 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/03 22:41:02 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < length)
	{
		if (f(tab[i]))
			counter++;
		i++;
	}
	return (counter);
}
