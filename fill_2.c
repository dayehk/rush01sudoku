/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:15:17 by daykim            #+#    #+#             */
/*   Updated: 2019/01/20 16:29:59 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		avlabl(int **num, int pos, int dgt);

int		ft_strcmp(int *s1, int *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_sdkcmp(int **num, int **num2)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if (ft_strcmp(num[i], num2[i]))
			return (0);
		i++;
	}
	return (1);
}

int		fillcell(int **num, int pos)
{
	int value;
	int row;
	int col;

	row = pos % 9;
	col = pos / 9;
	if (pos == 81)
		return (1);
	if (num[row][col] != 0)
		return (fillcell(num, pos + 1));
	value = 1;
	while (value <= 9)
	{
		if (avlabl(num, pos, value))
		{
			num[row][col] = value;
			if (fillcell(num, pos + 1))
				return (1);
			else
				num[row][col] = 0;
		}
		value++;
	}
	return (0);
}

int		fillcell_rev(int **num, int pos)
{
	int value;
	int row;
	int col;

	row = pos % 9;
	col = pos / 9;
	if (pos == 81)
		return (1);
	if (num[row][col] != 0)
		return (fillcell_rev(num, pos + 1));
	value = 9;
	while (value >= 1)
	{
		if (avlabl(num, pos, value))
		{
			num[row][col] = value;
			if (fillcell_rev(num, pos + 1))
				return (1);
			else
				num[row][col] = 0;
		}
		value--;
	}
	return (0);
}
