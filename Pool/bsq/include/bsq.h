#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define DEFAULT_EMPTY '.'
# define DEFAULT_FULL 'o'
# define DEFAULT_SQUARE 'x'

typedef struct s_map
{
	int		height;
	int		width;
	char	empty_c;
	char	full_c;
	char	square_c;
	char	**grid;
	int		**dp;
	int		best_size;
	int		best_row;
	int		best_col;
}	t_map;

/* reader.c */
char	*read_file(const char *path);
char	**split_lines(const char *content, int *line_count);

/* parser.c */
int		parse_map(char **lines, int line_count, t_map *map);

/* parser_utils.c */
int		ft_isdigit(char c);
int		is_valid_header_char(char c);
int		parse_header(const char *header, t_map *map, int *declared_height);

/* validator.c */
int		validate_map(t_map *map, int declared_height, int line_count,
			char **lines);

/* solver.c */
void	solve_map(t_map *map);

/* fill_square.c */
void	fill_square(t_map *map);

/* output.c */
void	print_map(t_map *map);
void	print_error(void);

/* free.c */
void	free_map(t_map *map);
void	free_lines(char **lines, int count);

/* utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		min3(int a, int b, int c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
