#include "bsq.h"

void	free_lines(char **lines, int count)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	if (map->dp)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->dp[i]);
			i++;
		}
		free(map->dp);
		map->dp = NULL;
	}
}
