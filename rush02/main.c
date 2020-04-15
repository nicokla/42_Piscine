/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:19:42 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:31:44 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	pronounce_decades_and_units(int n, int something_before)
{
	if (n >= 100)
		something_before = 1;
	if (!something_before && n == 0)
	{
		ft_putstr(g_units[0]);
		return ;
	}
	if ((n % 100) == 0)
		return ;
	if (n >= 100 || something_before)
		ft_putstr(" ");
	if (n % 100 < 20)
		ft_putstr(g_units[n % 100]);
	else
	{
		if (((n / 10) % 10) != 0)
			ft_putstr(g_decades[(n / 10) % 10]);
		if ((((n / 10) % 10 != 0) && n % 10 != 0) || something_before)
			ft_putstr(" ");
		if (n % 10 != 0)
			ft_putstr(g_units[n % 10]);
	}
}

void	pronounce_hundreds(int n, int something_before)
{
	if (n >= 100)
	{
		if (something_before)
			ft_putstr(" ");
		ft_putstr(g_units[n / 100]);
		ft_putstr(" ");
		ft_putstr(g_cent);
	}
}

void	pronounce_group_of_three(int k)
{
	int n;
	int something_before;

	something_before = k != g_last_group_of_three;
	n = g_sub_number[k];
	pronounce_hundreds(n, something_before);
	pronounce_decades_and_units(n, something_before);
	if (k > 0 && n != 0)
	{
		ft_putstr(" ");
		ft_putstr(g_thousands[k]);
	}
}

int		main(int argc, char **argv)
{
	int		error;
	int		k;
	int		fd;

	error = get_input(argc, argv);
	if (error == 1)
	{
		write(1, "error\n", 6);
		return (1);
	}
	fd = open("numbers.dict", O_RDONLY);
	get_dict(fd);
	prepare_sub_number();
	k = g_last_group_of_three;
	while (k >= 0)
		pronounce_group_of_three(k--);
	write(1, "\n", 1);
	free_dict();
	close(fd);
	return (0);
}
