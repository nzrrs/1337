#include "bsq.h"

void	fill_square(t_map *map)
{
	int	i;
	int	j;

	if (map->best_size <= 0)
		return ;
	i = map->best_row;
	while (i < map->best_row + map->best_size)
	{
		j = map->best_col;
		while (j < map->best_col + map->best_size)
		{
			map->grid[i][j] = map->square_c;
			j++;
		}
		i++;
	}
}
