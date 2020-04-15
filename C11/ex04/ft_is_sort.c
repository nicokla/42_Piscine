/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:44:55 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/19 10:44:57 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int compteur_inferieurs;
	int compteur_superieurs;

	if (length <= 2)
		return (1);
	compteur_inferieurs = 0;
	compteur_superieurs = 0;
	i = 1;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) < 0)
			compteur_inferieurs++;
		else if (((*f)(tab[i - 1], tab[i]) > 0))
			compteur_superieurs++;
		if (compteur_inferieurs && compteur_superieurs)
			return (0);
		i++;
	}
	return (1);
}
