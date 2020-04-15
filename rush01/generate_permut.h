/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_permut.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:12:14 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 11:14:16 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_PERMUT_H
#define GENERATE_PERMUT_H
#include "global.h"

char		g_all_permut[FACTORIEL_SIZE][SIZE];
void		swap(char *a, char *b);
void		init_permut(char *permut0);
void		compute_permutations(char *a, int i, int *p_compteur_permut);

#endif
