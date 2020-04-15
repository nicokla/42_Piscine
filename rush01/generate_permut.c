/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_permut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:13:55 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 12:38:28 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "global.h"

void	swap(char *a, char *b)
{
	char t;

	t = *b;
	*b = *a;
	*a = t;
}

void	init_permut(char *permut0)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		permut0[i] = i + 1;
		i++;
	}
}

void	compute_permutations(char *a, int i, int *p_compteur_permut)
{
	int j;

	if (i == (SIZE - 1))
	{
		j = 0;
		while (j <= (SIZE - 1))
		{
			g_all_permut[*p_compteur_permut][j] = a[j];
			j++;
		}
		(*p_compteur_permut)++;
	}
	else
	{
		j = i;
		while (j <= (SIZE - 1))
		{
			swap(&(a[i]), &(a[j]));
			compute_permutations(a, i + 1, p_compteur_permut);
			swap(&(a[i]), &(a[j]));
			j++;
		}
	}
}
