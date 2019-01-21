/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:41:50 by daykim            #+#    #+#             */
/*   Updated: 2019/01/20 16:14:29 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	avlabl(int **num, int pos, int dgt)
{
	int rowsec;
	int colsec;
	int i;
	int row;
	int col;

	row = pos % 9;
	col = pos / 9;
	rowsec = (row / 3) * 3;
	colsec = (col / 3) * 3;
	i = 0;
	while (i <= 8)
	{
		if (num[row][i] == dgt || num[i][col] == dgt)
			return (0);
		if (num[rowsec + (i / 3)][colsec + (i % 3)] == dgt)
			return (0);
		i++;
	}
	return (1);
}
