#include "bsq.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}

void	print_error(void)
{
	fprintf(stderr, "map error\n");
}
