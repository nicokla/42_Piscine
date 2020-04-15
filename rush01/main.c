/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:14:47 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 12:47:57 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "input.h"
#include "input_check.h"
#include "output.h"
#include "global.h"
#include "generate_permut.h"
#include "main.h"


Signature	sig_of_permut(Tableau *p_tab, int num, int is_ligne)
{
	Signature s;

	s.s[0] =
		sig_of_permut_sub(p_tab, num, is_ligne, 1);
	s.s[1] =
		sig_of_permut_sub(p_tab, num, is_ligne, 0);
	return (s);
}

int		sig_of_permut_sub(Tableau *p_tab, int num, int is_ligne, int from_start)
{
	int var;
	int max;
	int i;
	int compteur;
	int fin;

	i = 	(from_start * 0)		+ ((1 - from_start) * (SIZE - 1));
	fin = 	(1 - from_start) * 0 	+ (from_start * (SIZE - 1));
	max = 0;
	compteur = 0;
	while ((i <= fin) * from_start + (i >= fin) * (1 - from_start))
	{
		if (is_ligne)
			var = p_tab->t[num][i];
		else
			var = p_tab->t[i][num];
		if (var > max)
		{
			max = var;
			compteur++;
		}
		i += ((from_start * 1) 		+ (1 - from_start) * (-1));
	}
	return (compteur);
}

int signatures_are_equal(Signature s1, Signature s2)
{
	return (s1.s[0] == s2.s[0]
			&& s1.s[1] == s2.s[1]);
}


void	copier_ligne(int ligne, int indice_permut, Tableau *p_tab)
{
	int i;

	i = 0;
	while (i <= (SIZE - 1))
	{
		p_tab->t[ligne][i] = g_all_permut[indice_permut][i];
		i++;
	}
}


int		is_possible_final(Tableau *p_tab)
{
	int i;

	i = 0;
	while(i < SIZE)
	{
		if (!(signatures_are_equal(sig_of_permut(p_tab, i, 0),
		 							g_list_signatures[0][i])))
			return (0);
		i++;
	}
	return (1);
}

int		is_possible(Tableau *p_tab, int ligne)
{
	int l;
	int col;

	if (ligne == (-1))
		return (1);
	if (!(signatures_are_equal(sig_of_permut(p_tab, ligne, 1),
								g_list_signatures[1][ligne])))
		return (0);
	l = 0;
	while(l < ligne)
	{
		col = 0;
		while(col < SIZE)
		{
			if (p_tab->t[ligne][col] == p_tab->t[l][col])
				return (0);
			col++;
		}
		l++;
	}
	return (1);
}


int	recur(Tableau *p_tab, int ligne, int *p_compteur_answers)
{
	int i;

	if (ligne == (SIZE - 1))
	{
		if (is_possible(p_tab, ligne)
			&& is_possible_final(p_tab))
		{
			if ((*p_compteur_answers) == 0)
			{
				print_result(p_tab);
				return (0);
			}
			(*p_compteur_answers)++;
		}
	}
	else
	{
		if (is_possible(p_tab, ligne))
		{
			i = 0;
			while (i < FACTORIEL_SIZE)
			{
				copier_ligne(ligne + 1, i, p_tab);
				if(!recur(p_tab, ligne + 1, p_compteur_answers))
					return (0);
				i++;
			}
		}
	}
	return (1);
}

void init_tableau(Tableau *tab)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			tab->t[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char permut0[SIZE];
	Tableau tab;
	int compteur_answers;
	int compteur_permuts;

	compteur_answers = 0;
	compteur_permuts = 0;
	if (!is_good(argc, argv))
		return (print_error());
	get_signatures(argv[1]);
	if (!is_good2(g_list_signatures[0], g_list_signatures[1]))
		return (print_error());
	init_permut(permut0);
	init_tableau(&tab);
	compute_permutations(permut0, 0, &compteur_permuts);
	(void)recur(&tab, -1, &compteur_answers);
	return (0);
}
