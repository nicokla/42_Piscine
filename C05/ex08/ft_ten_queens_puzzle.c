/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:42:06 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 12:29:50 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_solution(int *tab)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (i <= 9)
	{
		c = (unsigned char)tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		is_possible(int ligne, int *tab)
{
	int ligne2;
	int a;
	int b;

	ligne2 = ligne - 1;
	while (ligne2 >= 0)
	{
		a = tab[ligne] + ligne - ligne2;
		b = tab[ligne] - (ligne - ligne2);
		if (tab[ligne2] == a
			|| tab[ligne2] == b
			|| tab[ligne2] == tab[ligne])
			return (0);
		ligne2--;
	}
	return (1);
}

void	find_solutions(int ligne, int *tab, int *p_nb_solutions)
{
	int i;

	if (ligne == 9)
	{
		if (is_possible(ligne, tab))
		{
			print_solution(tab);
			(*p_nb_solutions)++;
		}
	}
	else
	{
		if (is_possible(ligne, tab))
		{
			i = 0;
			while (i <= 9)
			{
				tab[ligne + 1] = i;
				find_solutions(ligne + 1, tab, p_nb_solutions);
				i++;
			}
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];
	int nb_solutions;
	int i;

	nb_solutions = 0;
	i = 0;
	while (i < 10)
	{
		tab[i] = 0;
		i++;
	}
	find_solutions(-1, tab, &nb_solutions);
	return (nb_solutions);
}
