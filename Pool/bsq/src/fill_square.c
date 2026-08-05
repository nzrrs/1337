/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnx <vnx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:20:00 by vnx               #+#    #+#             */
/*   Updated: 2026/08/05 15:20:00 by vnx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

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
