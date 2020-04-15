/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:09:19 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:01:19 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	get_dict_name(int fd, char *line, int *p_ret)
{
	int		pos;
	int		already_seen;
	char	tmp;

	pos = 1;
	already_seen = 0;
	tmp = line[0];
	while ((*p_ret) == 1 && !ft_is_end_of_line(tmp))
	{
		(*p_ret) = read(fd, &tmp, 1);
		if (!ft_is_space(tmp))
		{
			line[pos] = tmp;
			already_seen = 0;
			(pos)++;
		}
		if (ft_is_space(tmp) && !already_seen)
		{
			line[pos] = tmp;
			already_seen = 1;
			(pos)++;
		}
	}
	line[pos - 1] = '\0';
}

char	skip_space_and_two_points(int fd, char *line)
{
	char	c;
	int		ret;

	c = line[0];
	ret = 1;
	while (ret == 1 && ft_is_space(c))
		ret = read(fd, &c, 1);
	ret = read(fd, &c, 1);
	while (ret == 1 && (ft_is_space(c)))
		ret = read(fd, &c, 1);
	if (c != ' ')
		return (c);
	return (' ');
}

int		get_index(int length, int value)
{
	if (length == 3)
		return (28);
	else if (length >= 4)
		return ((length / 3) + 28);
	else if (value <= 20)
		return (value);
	else
		return ((value / 10) + 18);
}

int		get_dict_index(int fd, char *line, int *p_ret)
{
	int length;
	int value;
	int pos;

	pos = 0;
	line[0] = 'a';
	(*p_ret) = read(fd, line, 1);
	while (*p_ret == 1 && !(ft_is_space(line[pos]) || line[pos] == ':'))
	{
		(pos)++;
		(*p_ret) = read(fd, line + (pos), 1);
	}
	length = pos;
	value = ft_atoi(line);
	line[0] = line[pos];
	return (get_index(length, value));
}

void	get_dict(int fd)
{
	char	line[100];
	int		ret;
	int		num_line;
	int		index;

	num_line = 0;
	ret = 1;
	while (num_line < 41)
	{
		index = get_dict_index(fd, line, &ret);
		g_dict_indexes[index] = num_line;
		line[0] = skip_space_and_two_points(fd, line);
		get_dict_name(fd, line, &ret);
		g_dict[num_line] = ft_strdup(line);
		num_line++;
	}
	get_dict_aux();
}
