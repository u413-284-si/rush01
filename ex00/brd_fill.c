/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brd_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:34:22 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/11 20:34:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	inner_matrix(int arr[6][6]);

void	up_bound(int *table, int *nbr)
{
	int	t;
	int	n;

	t = 1;
	n = 0;
	while (t < 5)
	{
		*table = '\0';
		*(table + t) = nbr[n];
		t++;
		n++;
	}
	*(table + t) = '\0';
}

void	low_bound(int *table, int *nbr)
{
	int	t;
	int	n;

	t = 31;
	n = 4;
	while (t < 35)
	{
		*(table + 30) = '\0';
		*(table + t) = nbr[n];
		t++;
		n++;
	}
	*(table + t) = '\0';
}

void	left_bound(int *table, int *nbr)
{
	int	t;
	int	n;
	int	intervall;
	int	counter;

	t = 7;
	n = 8;
	intervall = 6;
	counter = 0;
	while (counter < 4)
	{
		*(table + t) = '\0';
		*(table + 6 + t) = '\0';
		*(table + 6 + (counter * intervall)) = nbr[n];
		counter++;
		n++;
		t++;
	}
	*(table + 6 + counter * intervall) = '\0';
}

void	right_bound(int *table, int *nbr)
{
	int	t;
	int	n;
	int	intervall;
	int	counter;

	t = 19;
	n = 12;
	intervall = 6;
	counter = 0;
	while (counter < 4)
	{
		*(table + t) = '\0';
		*(table + 6 + t) = '\0';
		*(table + 11 + (counter * intervall)) = nbr[n];
		counter++;
		n++;
		t++;
	}
	*(table + 11 + counter * intervall) = '\0';
}

void	brd_fill(int *nbr, int arr[6][6])
{
	up_bound(&arr[0][0], nbr);
	low_bound(&arr[0][0], nbr);
	left_bound(&arr[0][0], nbr);
	right_bound(&arr[0][0], nbr);
	inner_matrix(arr);
}
