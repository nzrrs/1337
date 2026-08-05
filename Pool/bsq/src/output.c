/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnx <vnx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:20:00 by vnx               #+#    #+#             */
/*   Updated: 2026/08/05 15:20:00 by vnx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	print_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->rows)
	{
		write(1, map->grid[row], map->cols);
		write(1, "\n", 1);
		row++;
	}
}

void	print_error(void)
{
	write(1, "map error\n", 10);
}
