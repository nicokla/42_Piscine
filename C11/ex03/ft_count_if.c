/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:44:43 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/19 10:44:45 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int compteur;

	compteur = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			compteur++;
		i++;
	}
	return (compteur);
}
