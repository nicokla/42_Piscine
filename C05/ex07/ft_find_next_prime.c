/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:41:50 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/13 13:26:58 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	calcule_borne(long nb)
{
	long i;
	long result;

	i = 0;
	result = i * i;
	while (result < nb && i <= 3037000499)
	{
		i++;
		result = i * i;
	}
	return (i);
}

long	ft_is_prime(long nb)
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

int		ft_find_next_prime(int nb)
{
	long i;
	long nb_long;

	nb_long = (long)nb;
	if (nb_long <= 2)
	{
		return (2);
	}
	i = nb_long;
	while (i < 2 * nb_long && i < 2147483648)
	{
		if (ft_is_prime(i) && i < 2147483648)
			return ((int)i);
		i++;
	}
	return (0);
}
