#include "bsq.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
** A header char must be a printable, non-whitespace, non-digit symbol.
** (printable ASCII range is 33-126, which excludes space and control chars)
*/
int	is_valid_header_char(char c)
{
	if (c < 33 || c > 126)
		return (0);
	if (ft_isdigit(c))
		return (0);
	return (1);
}

/*
** header format: <positive integer>[<empty><full><square>]
** the three extra chars are optional, but if present there must be
** exactly three, all distinct, all valid symbols.
*/
int	parse_header(const char *header, t_map *map, int *declared_height)
{
	int		i;
	long	n;

	i = 0;
	if (!header || !ft_isdigit(header[0]))
		return (0);
	n = 0;
	while (ft_isdigit(header[i]))
	{
		n = n * 10 + (header[i] - '0');
		if (n > 1000000)
			return (0);
		i++;
	}
	if (n <= 0)
		return (0);
	*declared_height = (int)n;
	if (header[i] == '\0')
	{
		map->empty_c = DEFAULT_EMPTY;
		map->full_c = DEFAULT_FULL;
		map->square_c = DEFAULT_SQUARE;
		return (1);
	}
	if (ft_strlen(header + i) != 3)
		return (0);
	if (!is_valid_header_char(header[i]) || !is_valid_header_char(header[i + 1])
		|| !is_valid_header_char(header[i + 2]))
		return (0);
	if (header[i] == header[i + 1] || header[i + 1] == header[i + 2]
		|| header[i] == header[i + 2])
		return (0);
	map->empty_c = header[i];
	map->full_c = header[i + 1];
	map->square_c = header[i + 2];
	return (1);
}
