/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:10:39 by daykim            #+#    #+#             */
/*   Updated: 2019/01/19 16:16:05 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	**get_input(int argc, char **argv)
{
	int	i;
	int	j;
	int	**num;

	num = (int **)malloc(sizeof(int *) * 9 + 1);
	i = 0;
	while (i <= 8)
	{
		if (argc != 10)
			return (0);
		num[i] = (int *)malloc(sizeof(int) * 9 + 1);
		j = 0;
		while (j <= 8)
		{
			if ('1' <= argv[i + 1][j] && argv[i + 1][j] <= '9')
				num[i][j] = argv[i + 1][j] - '0';
			else if (argv[i + 1][j] == '.')
				num[i][j] = 0;
			else
				return(0);
			j++;
		}
		i++;
	}
	return (num);
}

void	print_sudoku(int **sud)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 8)
	{
		j = 0;
		while (j <= 8)
		{
			ft_putchar(sud[i][j] + '0');
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
//	int **inp = get_input(argc, argv);
	print_sudoku(get_input(argc, argv));
	return (0);
}
