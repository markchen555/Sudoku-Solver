/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 13:16:28 by yooi              #+#    #+#             */
/*   Updated: 2016/08/21 15:27:25 by yooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		solver2(char arr[9][9], int row, int col)
{
	char nb;

	//final stopping condition. When the row number goes to the last cell.
	//means every single cell has been checked and filled with a valid number.
	if (row < 9 && col < 9)
	{
		//if the cell has default number filled in. 
		if (arr[row][col] != '.')
		{
			//this order makes sure we checks through all cells before reaching row == 9.
			if ((col + 1) < 9)
				return (sudoku_solver(arr, row, col + 1));
			else if ((row + 1) < 9)
				return (sudoku_solver(arr, row + 1, 0));
			else
				return (1);
		}
		//else if the cell is '.' -- need to fill in. Proceed to check.
		else
		{
			nb = '1';
			while (nb <= '9')
			{
				if (is_valid(nb, arr, row, col))
				{
					//conclusion for all checks to get the valid number.
					arr[row][col] = nb;
					//if nb is a valid option, recurse to check the subsequent cell
					//if any of the remaining cells can't find a valid number
					//this will set the current cell to be '.' again.
					if (sudoku_solver(arr, row, col))
						return 1;
					else
						arr[row][col] = '.';
				}
				nb++;
			}	
		}
		return (0);
	}
	else
		return (1);
}
