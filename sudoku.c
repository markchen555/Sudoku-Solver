/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 21:11:23 by smifsud           #+#    #+#             */
/*   Updated: 2016/08/21 15:34:39 by yooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

void	sudokumaker(char *str)
{
	int		i;
	char	arr[9][9];

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '.')
			arr[0][i] = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			arr[0][i] = str[i];
		else
			return ;
	}
}

void	sudoku_create(char	**argv, char arr[9][9])
{
	int		row;
	int		col;

	row = 1;
	col = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 9)
		{
			arr[row - 1][col] = argv[row][col];
			col++;
		}
		row++;
	}
}

int		main(int argc, char **argv)
{
	char	arr[9][9];

	if (argc == 10)
	{
		sudoku_create(argv, arr);
		if(solver2(arr, 0, 0))
			print_sudoku(arr);
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return(0);
}
