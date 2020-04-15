/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:49:30 by ale-baux          #+#    #+#             */
/*   Updated: 2019/06/25 23:30:37 by ale-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_obstacle(t_input *p_input, int i, int j)
{
	if (p_input->carte[(i * p_input->nb_columns) + j] == p_input->case_obstacle)
		return (1);
	return (0);
}

int		get_next_nb(t_input *p_input, t_output *p_output, int i, int j)
{
	int answer;
	int a;
	int b;

	a = p_output->tab[(i + 1) * p_input->nb_columns + j];
	b = p_output->tab[i * p_input->nb_columns + j + 1];
	answer = MIN(a, b) + 1;
	if (a == b)
	{
		if (is_obstacle(p_input, i + a, j + a))
			answer--;
	}
	return (answer);
}

void	compare_values(t_input *p_input, t_output *p_output, int i, int j)
{
	int nb_lines;
	int nb_col;

	nb_lines = p_input->nb_lines;
	nb_col = p_input->nb_columns;
	if (p_input->carte[(i * nb_col) + j] == p_input->case_obstacle)
		p_output->tab[(i * nb_col) + j] = 0;
	else if (i == nb_lines - 1 || j == nb_col - 1)
		p_output->tab[(i * nb_col) + j] = 1;
	else
		p_output->tab[(i * nb_col) + j] = get_next_nb(p_input, p_output, i, j);
	if (p_output->tab[(i * nb_col) + j] >= p_output->max)
	{
		p_output->max = p_output->tab[(i * nb_col) + j];
		p_output->i0 = i;
		p_output->j0 = j;
	}
}

void	solve(t_input *p_input, t_output *p_output)
{
	int nb_lines;
	int nb_columns;
	int i;
	int j;
	int sum;

	nb_lines = p_input->nb_lines;
	nb_columns = p_input->nb_columns;
	sum = nb_lines + nb_columns - 2;
	if (!(p_output->tab = malloc(sizeof(int) * nb_columns * nb_lines)))
		return ;
	p_output->max = 0;
	while (sum >= 0)
	{
		i = MIN(nb_lines - 1, sum);
		j = sum - i;
		while (j <= nb_columns - 1 && i >= 0)
		{
			compare_values(p_input, p_output, i, j);
			i--;
			j++;
		}
		sum--;
	}
	mettre_carre(p_input, p_output);
}
