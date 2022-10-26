/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:17:29 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/11 22:02:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	colxup(int array[6][6], int col);
int	colxdown(int array[6][6], int col);
int	rowxleft(int array[6][6], int row);
int	rowxright(int array[6][6], int row);

void	bruteforce(int arr[6][6])
{
	arr[1][1] = 2;
	arr[1][2] = 1;
	arr[1][3] = 4;
	arr[1][4] = 3;
	arr[2][1] = 4;
	arr[2][2] = 3;
	arr[2][3] = 2;
	arr[2][4] = 1;
	arr[3][1] = 3;
	arr[3][2] = 2;
	arr[3][3] = 1;
	arr[3][4] = 4;
	arr[4][1] = 1;
	arr[4][2] = 4;
	arr[4][3] = 3;
	arr[4][4] = 2;
}

void	check_solution(int arr[6][6], int row, int col, int row_check)
{
	while (col < 5)
	{
		if (row_check)
		{
			while (row < 5)
			{
				if (rowxleft(arr, row) || rowxright(arr, row))
				{
					bruteforce(arr);
					row = 1;
					continue ;
				}
				row++;
			}
			row_check = 0;
		}
		if (colxup(arr, col) || colxdown(arr, col))
		{
			bruteforce(arr);
			col = 1;
			row_check = 1;
			continue ;
		}	
		col++;
	}
}

void	inner_matrix(int arr[6][6])
{	
	int	row;
	int	col;
	int	row_check;

	row = 1;
	col = 1;
	row_check = 1;
	bruteforce(arr);
	check_solution(arr, row, col, row_check);
}
