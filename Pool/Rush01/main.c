/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:24:10 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/25 17:35:10 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(unsigned nbr);
int		ft_parser(char *str, int *clues);

int	main(int ac, char **av)
{
	int	clues[16] = {0};

	if (!(ft_parser(av[1], clues)) || ac != 2)
	{
		return (0);
	}
}
