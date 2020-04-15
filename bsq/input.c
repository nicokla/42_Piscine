/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:30:17 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/25 17:30:19 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		saut_de_ligne_is_ok(int fd)
{
	char	c;
	int		ret;

	ret = read(fd, &c, 1);
	if ((ret < 0) || c != '\n')
		return (0);
	return (1);
}

int		line_is_ok(t_input *p_input, int i)
{
	int		j;
	int		nb_col;
	char	c1;
	char	c2;
	char	c;

	j = 0;
	nb_col = p_input->nb_columns;
	c1 = p_input->case_vide;
	c2 = p_input->case_obstacle;
	while (j < nb_col)
	{
		c = p_input->carte[i * nb_col + j];
		if (!(c == c1 || c == c2))
			return (0);
		j++;
	}
	return (j > 0);
}

int		get_first_line_from_list(t_input *p_input,
								t_list **p_elt, int i)
{
	int total;

	total = p_input->nb_columns;
	while (*p_elt != NULL)
	{
		while (i > 0)
		{
			p_input->carte[--total] = (*p_elt)->s[--i];
		}
		i = BUF_SIZE;
		*p_elt = (*p_elt)->next;
	}
	ft_list_clear(*p_elt);
	if (!line_is_ok(p_input, 0))
		return (1);
	return (0);
}

int		get_other_lines(t_input *p_input, int fd)
{
	int i;
	int ret;

	i = 1;
	while (i < p_input->nb_lines
			&& (ret = read(fd,
							p_input->carte + (i * p_input->nb_columns),
							p_input->nb_columns)) > 0)
	{
		if (!saut_de_ligne_is_ok(fd))
			return (1);
		if (!line_is_ok(p_input, i))
			return (1);
		i++;
	}
	return (i < p_input->nb_lines);
}

int		get_input(t_input *p_input, int fd)
{
	int		i;
	t_list	*elt;

	if (get_nb_lignes_and_symbols(p_input, fd))
		return (1);
	i = 0;
	p_input->nb_columns = compute_nb_columns(p_input, fd, &i, &elt);
	if (p_input->nb_columns == (-1))
		return (1);
	if ((p_input->carte =
			malloc(p_input->nb_columns * p_input->nb_lines)) == NULL)
		return (1);
	if (get_first_line_from_list(p_input, &elt, i))
		return (1);
	if (get_other_lines(p_input, fd))
		return (1);
	return (0);
}
