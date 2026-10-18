/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:09:24 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/05 17:13:16 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(t_map *map, t_square square)
{
	int	start_row;
	int	start_col;
	int	row;
	int	col;

	if (square.size <= 0)
		return ;
	start_row = square.row - square.size + 1;
	start_col = square.col - square.size + 1;
	row = start_row;
	while (row <= square.row)
	{
		col = start_col;
		while (col <= square.col)
		{
			map->grid[row][col] = map->full;
			col++;
		}
		row++;
	}
}
