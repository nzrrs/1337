#include "bsq.h"

static int	*alloc_dp_row(int width)
{
	return (ft_calloc(width, sizeof(int)));
}

/*
** classic "maximal square" DP:
** dp[i][j] = size of the largest all-empty square whose bottom-right
** corner is (i, j). If the cell is an obstacle, dp[i][j] = 0.
** Otherwise dp[i][j] = 1 + min(top, left, top-left) neighbours,
** or 1 if on the first row/column.
*/
void	solve_map(t_map *map)
{
	int	i;
	int	j;

	map->dp = malloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		map->dp[i] = alloc_dp_row(map->width);
		i++;
	}
	map->best_size = 0;
	map->best_row = 0;
	map->best_col = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == map->empty_c)
			{
				if (i == 0 || j == 0)
					map->dp[i][j] = 1;
				else
					map->dp[i][j] = 1 + min3(map->dp[i - 1][j],
							map->dp[i][j - 1], map->dp[i - 1][j - 1]);
				if (map->dp[i][j] > map->best_size)
				{
					map->best_size = map->dp[i][j];
					map->best_row = i - map->best_size + 1;
					map->best_col = j - map->best_size + 1;
				}
			}
			j++;
		}
		i++;
	}
}
