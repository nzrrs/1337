#include "bsq.h"

static int	process_map(const char *path)
{
	char	*content;
	char	**lines;
	int		line_count;
	t_map	map;

	memset(&map, 0, sizeof(t_map));
	content = read_file(path);
	if (!content)
	{
		print_error();
		return (1);
	}
	lines = split_lines(content, &line_count);
	free(content);
	if (!lines)
	{
		print_error();
		return (1);
	}
	if (!parse_map(lines, line_count, &map))
	{
		print_error();
		free_lines(lines, line_count);
		free_map(&map);
		return (1);
	}
	free_lines(lines, line_count);
	solve_map(&map);
	fill_square(&map);
	print_map(&map);
	free_map(&map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	status;

	status = 0;
	if (argc == 1)
		status = process_map(NULL);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (process_map(argv[i]) != 0)
				status = 1;
			i++;
		}
	}
	return (status);
}
