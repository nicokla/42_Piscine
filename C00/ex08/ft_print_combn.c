/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:04:25 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/06 15:04:32 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_chiffre(int n)
{
	char c;

	c = (n % 10) + 48;
	write(1, &c, 1);
}

void	print_liste(int *chiffres, int nombre_de_chiffres)
{
	int i;

	i = nombre_de_chiffres - 1;
	while (i >= 0)
	{
		print_chiffre(chiffres[i]);
		i--;
	}
}

void	sous_fonction(int *chiffres, int a, int *p_2)
{
	while (p_2 >= chiffres)
	{
		*p_2 = a;
		p_2--;
		a++;
	}
}

int		traite_nombre(int *chiffres, int nombre_de_chiffres)
{
	int *p_mon_chiffre;
	int *p_2;
	int a;

	a = 9;
	print_liste(chiffres, nombre_de_chiffres);
	p_mon_chiffre = chiffres;
	while (p_mon_chiffre - chiffres < nombre_de_chiffres
		&& *p_mon_chiffre == a)
	{
		p_mon_chiffre++;
		a--;
	}
	if (p_mon_chiffre == (chiffres + nombre_de_chiffres))
	{
		return (0);
	}
	(*p_mon_chiffre)++;
	a = (*p_mon_chiffre) + 1;
	p_2 = p_mon_chiffre - 1;
	sous_fonction(chiffres, a, p_2);
	return (1);
}

void	ft_print_combn(int nombre_de_chiffres)
{
	int		chiffres[9];
	int		i;
	int		j;
	char	virgule;
	char	espace;

	virgule = ',';
	espace = ' ';
	i = nombre_de_chiffres - 1;
	j = 0;
	while (i >= 0)
	{
		chiffres[i] = j;
		i--;
		j++;
	}
	while (traite_nombre(chiffres, nombre_de_chiffres))
	{
		write(1, &virgule, 1);
		write(1, &espace, 1);
	}
}
