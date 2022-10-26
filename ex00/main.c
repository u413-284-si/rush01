/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:59:26 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/13 15:40:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		error_check(char *str);
int		*split(char *str, int *dest);
void	brd_fill(int *nbrs, int prebrd[6][6]);
int		play(int *tbl, int index);
/*

*/
int	*split(char *str, int *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			dest[j] = str[i - 1] - '0';
			j++;
		}
		i++;
	}
	dest[j] = str[i - 1] - '0';
	return (dest);
}

void	convert(int temp[4][4], int *output)
{
	int	k;
	int	l;
	int	m;

	k = 0;
	m = 0;
	while (k < 4)
	{	
		l = 0;
		while (l < 4)
		{
			output[m] = temp[k][l];
			l++;
			m++;
		}
		k++;
	}
}

void	extract(int arr[6][6], int *output)
{
	int	i;
	int	j;
	int	temp[4][4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp[i][j] = arr[i + 1][j + 1];
			j++;
		}
		i++;
	}
	convert(temp, output);
}

void	output(int arr[16])
{
	int		count;
	char	arrout[16];

	count = 0;
	while (count < 16)
	{
		arrout[count] = arr[count] + '0';
		write(1, &arrout[count], 1);
		if ((count + 1) % 4 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		count++;
	}
}

int	main(int argc, char **argv)
{
	int	*nbr;
	int	prebrd[6][6];
	int	final[16];

	(void) argc;
	if (error_check(argv[1]) || argv[2])
	{
		write(1, "Error\n", 6);
		return (0);
	}
	nbr = (int *) malloc (16 * sizeof (int));
	split(argv[1], nbr);
	if (play(nbr, 0) || play(nbr, 8))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	brd_fill(nbr, prebrd);
	extract(prebrd, final);
	output(final);
	return (0);
}
	// 	int c = 0;
	// while (c < 6)
	// {
	// 	printf("%d ", prebrd[0][c]);
	// 	c++;
	// }
	// printf("\n");
	// while (c < 12)
	// {
	// 	printf("%d ", prebrd[0][c]);
	// 	c++;
	// }
	// printf("\n");
	// while (c < 18)
	// {
	// 	printf("%d ", prebrd[0][c]);
	// 	c++;
	// }
	// printf("\n");
	// while (c < 24)
	// {
	// 	printf("%d ", prebrd[0][c]);
	// 	c++;
	// }
	// printf("\n");
	// while (c < 30)
	// {
	// 	printf("%d ", prebrd[0][c]);
	// 	c++;
	// }
	// printf("\n");
	// while (c < 36)
	// {
	// 	printf("%d ", prebrd[0][c]);
	// 	c++;
	// }
	// printf("\n");