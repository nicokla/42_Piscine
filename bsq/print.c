/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:36:29 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/25 17:36:37 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	mettre_carre(t_input *p_input, t_output *p_output)
{
	int i;
	int j;
	int i_max;
	int j_max;

	i_max = p_output->i0 + p_output->max;
	j_max = p_output->j0 + p_output->max;
	i = p_output->i0;
	while (i < i_max)
	{
		j = p_output->j0;
		while (j < j_max)
		{
			p_input->carte[i * p_input->nb_columns + j] = p_input->case_carre;
			j++;
		}
		i++;
	}
}

void	print(t_input *p_input)
{
	int i;
	int i_max;

	i_max = p_input->nb_lines;
	i = 0;
	while (i < i_max)
	{
		write(1,
			&(p_input->carte[i * p_input->nb_columns]),
			p_input->nb_columns);
		write(1, "\n", 1);
		i++;
	}
}

void	print_2(t_input *p_input, t_output *p_output)
{
	int		i;
	int		i_max;
	int		j;
	int		j_max;
	char	c;

	i_max = p_input->nb_lines;
	j_max = p_input->nb_columns;
	i = 0;
	while (i < i_max)
	{
		j = 0;
		while (j < j_max)
		{
			c = (char)(p_output->tab[i * p_input->nb_columns + j]) + '0';
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
