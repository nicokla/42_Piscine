/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:02:41 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:14:27 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		get_offset(int *p_bool_zero)
{
	int i;
	int bool_zero;

	i = 0;
	bool_zero = 0;
	while (g_buf[i] == ' ')
		i++;
	while (g_buf[i] == '0')
	{
		bool_zero = 1;
		i++;
	}
	(*p_bool_zero) = bool_zero;
	return (i);
}

int		input_is_valid(int bool_zero)
{
	int i;

	i = 0;
	while (i < BUF_SIZE && g_buf[i] != '\0')
	{
		if (!(g_buf[i] <= '9' && g_buf[i] >= '0'))
			return (0);
		i++;
	}
	if (i == 0 && bool_zero)
	{
		g_buf[0] = '0';
		g_buf[1] = '\0';
	}
	return (i < 40 && (i > 0 || bool_zero));
}

void	set_offset_buffer(int offset)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = 'a';
	while (tmp != '\0' && i < BUF_SIZE)
	{
		tmp = g_buf[offset + i];
		g_buf[i] = tmp;
		i++;
	}
}

int		get_input(int argc, char **argv)
{
	int ret;
	int offset;
	int bool_zero;

	if (argc > 2)
		return (1);
	if (argc == 1 && !isatty(fileno(stdin)))
	{
		ret = read(STDIN_FILENO, g_buf, BUF_SIZE);
		if (ret <= 0)
			return (1);
		else
			g_buf[ret - 1] = '\0';
	}
	else if (argc == 2)
		(void)ft_strlcpy(g_buf, argv[1], BUF_SIZE);
	else
		return (1);
	offset = get_offset(&bool_zero);
	set_offset_buffer(offset);
	return (!input_is_valid(bool_zero));
}
