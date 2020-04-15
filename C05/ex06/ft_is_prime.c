/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:41:33 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/11 18:41:35 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		calcule_borne(int nb)
{
	int i;
	int result;

	i = 0;
	result = i * i;
	while (result < nb && i <= 46340)
	{
		i++;
		result = i * i;
	}
	return (i);
}

int		ft_is_prime(int nb)
{
	int diviseur;
	int reste;
	int borne;

	if (nb <= 1)
		return (0);
	else if (nb <= 3 || nb == 5)
		return (1);
	else if (nb % 2 == 0)
		return (0);
	diviseur = 3;
	reste = nb % diviseur;
	borne = calcule_borne(nb);
	while (reste != 0 && diviseur <= borne)
	{
		diviseur += 2;
		reste = nb % diviseur;
	}
	return (reste != 0);
}
