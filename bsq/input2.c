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

int		atoi_length(char *s, int length)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (i < length
		&& s[i] <= '9'
		&& s[i] >= '0')
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	return (result);
}

int		get_nb_lignes_and_symbols(t_input *p_input, int fd)
{
	char	buf[30];
	int		ret;
	int		i;

	i = 0;
	while (((ret = read(fd, &(buf[i]), 1)) > 0)
			&& i < 30
			&& buf[i] != '\n')
		i++;
	if (i >= 14)
		return (-1);
	p_input->nb_lines = atoi_length(buf, i - 3);
	p_input->case_vide = buf[i - 3];
	p_input->case_obstacle = buf[i - 2];
	p_input->case_carre = buf[i - 1];
	return (ret == (-1) || p_input->nb_lines <= 0);
}

int		compute_nb_columns(t_input *ppp, int fd, int *pi, t_list **p_elt)
{
	int		total;
	char	*buf;
	int		ret;

	total = 0;
	if ((buf = malloc(BUF_SIZE)) == NULL)
		return (-1);
	if ((*p_elt = ft_create_elem(buf)) == NULL)
		return (-1);
	while ((ret = read(fd, buf + (*pi), 1)) > 0 && buf[*pi] != '\n'
			&& (buf[*pi] == ppp->case_vide || buf[*pi] == ppp->case_obstacle))
	{
		(*pi)++;
		total++;
		if (*pi == BUF_SIZE && buf[*pi] != '\n')
		{
			*pi = 0;
			if ((buf = malloc(BUF_SIZE)) == NULL)
				return (-1);
			ft_list_push_front(p_elt, buf);
		}
	}
	return (buf[*pi] == '\n' ? total : (-1));
}
