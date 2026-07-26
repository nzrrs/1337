/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:07:11 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 17:15:29 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_deplicates(int board[4][4], int row, int col, int nbr);
int	check_top_visibility(int board[4][4], int col, int *clues);
int	check_bottom_visibility(int board[4][4], int col, int *clues);
int	check_left_visibility(int board[4][4], int row, int *clues);
int	check_right_visibility(int board[4][4], int row, int *clues);

int	solve_recursive(int board[4][4], int row, int col, int *clues)
{
	int	nbr;
	int	next_col;
	int	next_row;

	if (row == 4)
		return (1);
	nbr = 1;
	while (nbr <= 4)
	{
		if (check_deplicates(board, row, col, nbr))
		{
			board[row][col] = nbr;
			if (col == 3 && !(check_left_visibility(board, row, clues)
					&& check_right_visibility(board, row, clues)))
			{
				board[row][col] = 0;
				nbr++;
				continue ;
			}
			if (row == 3 && !(check_top_visibility(board, col, clues)
					&& check_bottom_visibility(board, col, clues)))
			{
				board[row][col] = 0;
				nbr++;
				continue ;
			}
			if (col < 3)
			{
				next_row = row;
				next_col = col + 1;
			}
			else
			{
				next_row = row + 1;
				next_col = 0;
			}
			if (solve_recursive(board, next_row, next_col, clues))
				return (1);
			board[row][col] = 0;
		}
		nbr++;
	}
	return (0);
}
int	solver(int board[4][4], int row, int col, int *clues)
{
	return (solve_recursive(board, row, col, clues));
}
