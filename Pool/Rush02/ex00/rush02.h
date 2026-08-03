/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:49:27 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:56:04 by kcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	char	*key;
	char	*val;
}			t_dict;

typedef struct s_line
{
	int	key_start;
	int	key_end;
	int	val_start;
	int	val_end;
}			t_line;

char	*load_file(char *filename, int *size);
char	*ft_get_val(char *str, t_dict *dict);
char	*get_magnitude(int zeros, t_dict *dict);
char	*pad_number(char *num, int *total);
t_dict	*parse_dict(char *filename);
void	free_dict(t_dict *dict);
int		ft_strlen(char *str);
int		is_valid_number(char *str);
int		parse_line(char *buf, int *i, t_line *part);
int		count_entries(char *buf);
int		fill_dict(t_dict *dict, char *buf);
int		print_word(char *str, int *first);
int		handle_three(char *num, t_dict *dict, int *first);
int		convert_chunks(char *tmp, int total, t_dict *dict, int *first);
int		ft_convert(char *num, t_dict *dict, int *first);
int		read_stdin(t_dict *dict);
int		print_number(char *num, t_dict *dict);

#endif
