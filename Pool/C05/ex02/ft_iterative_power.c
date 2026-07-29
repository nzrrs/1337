/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:38:08 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/25 18:38:10 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (result);
}
