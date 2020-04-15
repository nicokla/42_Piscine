/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:54:24 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/05 20:54:40 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_chiffre(int n)
{
	char c;
	char c2;

	c = (n % 10) + 48;
	c2 = (n / 10) + 48;
	write(1, &c2, 1);
	write(1, &c, 1);
}

void	print_liste(int *chiffres)
{
	print_chiffre(chiffres[1]);
	ft_putchar(' ');
	print_chiffre(chiffres[0]);
}

int		traite_nombre(int *chiffres)
{
	int *p_mon_chiffre;
	int *p_2;
	int a;

	a = 99;
	p_mon_chiffre = chiffres;
	while (p_mon_chiffre - chiffres < 2 && *p_mon_chiffre == a)
	{
		p_mon_chiffre++;
		a--;
	}
	if (p_mon_chiffre == (chiffres + 2))
	{
		return (0);
	}
	(*p_mon_chiffre)++;
	a = (*p_mon_chiffre) + 1;
	p_2 = p_mon_chiffre - 1;
	while (p_2 >= chiffres)
	{
		*p_2 = a;
		p_2--;
		a++;
	}
	return (1);
}

void	ft_print_comb2(void)
{
	int chiffres[2];
	int my_bool;

	chiffres[0] = 1;
	chiffres[1] = 0;
	my_bool = 1;
	while (my_bool)
	{
		print_liste(chiffres);
		my_bool = traite_nombre(chiffres);
		if (my_bool)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}
