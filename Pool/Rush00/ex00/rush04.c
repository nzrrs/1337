/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:01:25 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/18 16:35:27 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_firstrow(int x, int cols)
{
	if (cols == 1)
	{
		ft_putchar('A');
	}
	else if (cols == x)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}

void	ft_lastrow(int x, int cols)
{
	if (cols == 1)
	{
		ft_putchar('C');
	}
	else if (cols == x)
	{
		ft_putchar('A');
	}
	else
	{
		ft_putchar('B');
	}
}

void	ft_other(int x, int cols)
{
	if (cols == 1 || cols == x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	ft_triangle(int x, int y, int rows, int cols)
{
	if (rows == 1)
	{
		ft_firstrow(x, cols);
	}
	else if (rows == y)
	{
		ft_lastrow(x, cols);
	}
	else
	{
		ft_other(x, cols);
	}
}

void	rush(int x, int y)
{
	int	rows;
	int	cols;

	rows = 1;
	while (rows <= y)
	{
		cols = 1;
		while (cols <= x)
		{
			ft_triangle(x, y, rows, cols);
			cols++;
		}
		ft_putchar('\n');
		rows++;
	}
}
