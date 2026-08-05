/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnx <vnx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:20:00 by vnx               #+#    #+#             */
/*   Updated: 2026/08/05 15:20:00 by vnx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	process_fd(int fd)
{
	char		*content;
	int			size;
	t_map		map;
	t_square	square;

	content = read_all(fd, &size);
	if (!content || !parse_map(content, size, &map))
	{
		print_error();
		free(content);
		return ;
	}
	free(content);
	square = solve_map(&map);
	fill_square(&map, square);
	print_map(&map);
	free_map(&map);
}

void	process_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error();
		return ;
	}
	process_fd(fd);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_fd(0);
	i = 1;
	while (i < argc)
	{
		process_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
