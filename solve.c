/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:41:50 by daykim            #+#    #+#             */
/*   Updated: 2019/01/19 16:29:09 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	avlabl(int **num, int row, int col, int dgt)
{
	int rowsec;
	int colsec;
	int i;

	rowsec = (row / 3) * 3;
	colsec = (col / 3) * 3;
	i = 0;
	while (i <= 8)
	{
		if(num[row][i] == dgt || num[i][col] == dgt)
			return (0);
		if(num[rowsec + (i / 3)][colsec + (i % 3)] == dgt)
			return (0);
	}
	return (1);
}


