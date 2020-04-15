/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:35:16 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 19:35:17 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				sous_fonction(char *chiffres, int n, int i)
{
	i = 0;
	while (i < 10 && n > 0)
	{
		chiffres[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (i > 0)
		i--;
	while (i >= 0)
	{
		write(1, chiffres + i, 1);
		i--;
	}
}

void				ft_putnbr(int n)
{
	char	chiffres[10];
	int		i;

	i = 0;
	chiffres[0] = 48;
	if (n < 0)
	{
		write(1, "-", 1);
		if (n != -2147483648)
			n = -n;
		else
		{
			sous_fonction(chiffres, 214748364, i);
			write(1, "8", 1);
			return ;
		}
	}
	sous_fonction(chiffres, n, i);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != NULL)
	{
		write(1, par[i].str, ft_strlen(par[i].str));
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ft_strlen(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
