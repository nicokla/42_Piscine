/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:20:52 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/15 01:11:16 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		(*range) = NULL;
		return (0);
	}
	(*range) = malloc(sizeof(int) * (max - min));
	if ((*range) == NULL)
		return (-1);
	i = 0;
	while ((min + i) < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
