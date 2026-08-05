#include "bsq.h"

int	parse_map(char **lines, int line_count, t_map *map)
{
	int	declared_height;
	int	i;

	if (line_count < 2)
		return (0);
	if (!parse_header(lines[0], map, &declared_height))
		return (0);
	if (!validate_map(map, declared_height, line_count, lines))
		return (0);
	map->height = declared_height;
	map->width = (int)ft_strlen(lines[1]);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = ft_strdup(lines[i + 1]);
		if (!map->grid[i])
			return (0);
		i++;
	}
	map->grid[map->height] = NULL;
	return (1);
}
