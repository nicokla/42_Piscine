/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:20:12 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 19:20:16 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
		return ((int*)(0));
	tab = malloc(sizeof(int) * (max - min));
	i = 0;
	while ((min + i) < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
