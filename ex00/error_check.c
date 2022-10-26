/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:34:27 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/11 21:01:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	play(int *tbl, int index)
{
	int	intervall;
	int	checksum;
	int	one;
	int	start;

	start = index;
	intervall = 4;
	one = 0;
	while (index < start + intervall)
	{
		checksum = tbl[index] + tbl[index + intervall];
		if (checksum < 3 || checksum > 5)
			return (1);
		if (tbl[index] == 1 || tbl[index + intervall] == 1)
			one++;
		index++;
	}
	if (one != 2)
		return (1);
	return (0);
}

int	error_check(char *str)
{
	int	i;

	i = 0;
	if (str_len(str) != 31)
		return (1);
	while (str[i])
	{
		if (str[i] == ' ')
		{
			if (str[i - 2] == '-' || str[i - 1] < '1' || str[i - 1] > '4')
			{
				return (1);
			}
		}
		i++;
	}
	if (str[i - 2] == '-' || str[i -1] < '1' || str[i - 1] > '4')
	{
		return (1);
	}
	return (0);
}
