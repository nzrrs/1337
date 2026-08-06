/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:07:45 by nsadiki           #+#    #+#             */
/*   Updated: 2026/08/04 19:50:15 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_arguments(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if ((ft_strlen(av[2]) != 1))
	{
		ft_putstr("0\n");
		return (0);
	}
	return (1);
}

int	ft_get_operator_index(char **av)
{
	char	*ops;
	char	op;
	int		i;

	ops = "+-/*%";
	op = av[2][0];
	i = 0;
	while (ops[i])
	{
		if (op == ops[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_zero(int op, int b)
{
	if ((op == 2 || op == 4) && b == 0)
	{
		if (op == 2)
			ft_putstr("Stop : division by zero");
		if (op == 4)
			ft_putstr("Stop : modulo by zero");
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

void	ft_init_operations(int (*f[5])(int, int))
{
	f[0] = ft_plus;
	f[1] = ft_minus;
	f[2] = ft_divide;
	f[3] = ft_multiply;
	f[4] = ft_modulo;
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	op;
	int	(*f[5])(int, int);

	if (!(ft_check_arguments(ac, av)))
		return (0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	op = ft_get_operator_index(av);
	if (op == -1)
	{
		ft_putnbr(0);
		return (0);
	}
	if (!ft_check_zero(op, b))
		return (0);
	ft_init_operations(f);
	ft_putnbr(f[op](a, b));
	ft_putchar('\n');
	return (0);
}
