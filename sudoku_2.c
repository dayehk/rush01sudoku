/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:10:39 by daykim            #+#    #+#             */
/*   Updated: 2019/01/20 16:30:01 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		fillcell(int **num, int pos);
int		fillcell_rev(int **num, int pos);
int		ft_strcmp(int *s1, int *s2);
int		ft_sdkcmp(int **num, int **num2);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		**get_input(int argc, char **argv)
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
				return (0);
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

int		main(int argc, char **argv)
{
	int		**num;
	int		**num2;
	int		i;

	i = 0;
	num = get_input(argc, argv);
	num2 = get_input(argc, argv);
	if (num == 0)
		write(1, "Error1\n", 6);
	else if (fillcell(num, 0))
	{
		fillcell_rev(num2, 0);
		if (ft_sdkcmp(num, num2))
			print_sudoku(num);
		else
			write(1, "Error2\n", 6);
	}
	else
		write(1, "Error3\n", 6);
	return (0);
}
