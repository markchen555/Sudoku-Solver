/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 21:12:53 by smifsud           #+#    #+#             */
/*   Updated: 2016/08/21 15:58:03 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		check_row(char nb, char arr[9][9], int pos)
{
	int		x;

	x = 0;
	while (x < 9)
	{
		if (arr[pos][x] == nb)
			return (0);
		x++;
	}
	return (1);
}

int		check_column(char nb, char arr[9][9], int pos)
{
	int		y;

	y = 0;
	while (y < 9)
	{
		if (arr[y][pos] == nb)
			return (0);
		y++;
	}
	return (1);
}

int		check_box(char nb, char arr[9][9], int pos1, int pos2)
{
	int		x;

	x = 0;
	ft_putnbr(pos1);
	ft_putchar(' ');
	ft_putnbr(pos2);
	ft_putchar('\n');
	ft_putstr("checking box p1\n");
	while (x < 2)
	{
		if (arr[pos1][pos2 + x] == nb)
			return (0);
		x++;
	}
	x = 0;
	ft_putstr("checking box p2\n");
	while (x < 2)
	{
		if (arr[pos1 + 1][pos2 + x] == nb)
			return (0);
		x++;
	}
	x = 0;
	ft_putstr("checking box p3\n");
	while (x < 2)
	{
		if (arr[pos2 + 2][pos1 + x] == nb)
			return (0);
		x++;
	}
	return (1);
}

int		is_valid(char nb, char arr[9][9], int pos1, int pos2)
{
	if (check_row(nb, arr, pos1) != 1)
		return (0);
	if (check_column(nb, arr, pos2) != 1)
		return (0);
	if (pos1 > 6 || pos2 > 6)
	{
		if (check_box(nb, arr, pos1, pos2) != 1)
			return (0);
	}
	return (1);
}
