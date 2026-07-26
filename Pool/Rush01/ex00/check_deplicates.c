/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:55:32 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 15:13:08 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row(int board[4][4], int row, int nbr)
{
	int	col;

	col = 0;
	while (board[row][col])
	{
		if (board[row][col] == nbr)
		{
			return (0);
		}
		col++;
	}
	return (1);
}

int	check_col(int board[4][4], int col, int nbr)
{
	int	row;

	row = 0;
	while (board[row][col])
	{
		if (board[row][col] == nbr)
		{
			return (0);
		}
		row++;
	}
	return (1);
}

int	check_deplicates(int board[4][4], int row, int col, int nbr)
{
	if (!(check_col(board, col, nbr) && check_row(board, row, nbr)))
	{
		return (0);
	}
	return (1);
}
