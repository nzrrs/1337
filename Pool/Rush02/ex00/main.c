/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:48:49 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/08/02 18:55:42 by kcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_ac(int ac, char **av, char **num, char **dict_path)
{
	if (ac == 2)
		*num = av[1];
	else if (ac == 3)
	{
		*dict_path = av[1];
		*num = av[2];
	}
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	*dict_path;
	char	*num;
	t_dict	*dict;
	int		ok;

	dict_path = "numbers.dict";
	if (!ft_check_ac(ac, av, &num, &dict_path))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	dict = parse_dict(dict_path);
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (num[0] == '-' && num[1] == '\0')
		ok = read_stdin(dict);
	else
		ok = print_number(num, dict);
	free_dict(dict);
	if (!ok)
		return (1);
	return (0);
}
