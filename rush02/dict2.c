/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:09:35 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:14:13 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(void)
{
	int j;

	j = 0;
	while (j < 20)
		free(g_units[j++]);
	j = 2;
	while (j < 10)
		free(g_decades[j++]);
	free(g_cent);
	j = 1;
	while (j < 13)
		free(g_thousands[j++]);
	j = 0;
	while (j < 41)
		free(g_dict[j++]);
}

void	get_dict_aux(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < 20)
		g_units[j++] = ft_strdup(g_dict[g_dict_indexes[i++]]);
	j = 2;
	while (j < 10)
		g_decades[j++] = ft_strdup(g_dict[g_dict_indexes[i++]]);
	g_cent = ft_strdup(g_dict[g_dict_indexes[i++]]);
	j = 1;
	while (j < 13)
		g_thousands[j++] = ft_strdup(g_dict[g_dict_indexes[i++]]);
}
