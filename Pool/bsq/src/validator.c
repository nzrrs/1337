#include "bsq.h"

int	validate_map(t_map *map, int declared_height, int line_count,
		char **lines)
{
	int	i;
	int	j;
	int	width;

	if (declared_height != line_count - 1)
		return (0);
	if (declared_height <= 0)
		return (0);
	width = (int)ft_strlen(lines[1]);
	if (width <= 0)
		return (0);
	i = 1;
	while (i <= declared_height)
	{
		if ((int)ft_strlen(lines[i]) != width)
			return (0);
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] != map->empty_c && lines[i][j] != map->full_c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
