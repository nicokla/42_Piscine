/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:17:22 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/13 12:17:47 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isspace(char a)
{
	int answer;

	answer = (a == ' ')
		|| (a == '\n')
		|| (a == '\t')
		|| (a == '\v')
		|| (a == '\f')
		|| (a == '\r');
	return (answer);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		base_est_ok(char *base, int n)
{
	int i;
	int j;

	i = 0;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i <= n - 2)
	{
		j = i + 1;
		while (j <= n - 1)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	sous_fonction_1(char *chiffres, long nbr,
						int n, char *base)
{
	int i;

	i = 0;
	while (nbr > 0)
	{
		chiffres[i] = (nbr % n);
		nbr /= n;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, base + chiffres[i], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		n;
	long	nbr2;
	char	chiffres[33];

	n = ft_strlen(base);
	if (!base_est_ok(base, n))
		return ;
	nbr2 = (long)nbr;
	if (nbr2 < 0)
	{
		write(1, "-", 1);
		nbr2 = (0 - nbr2);
	}
	sous_fonction_1(chiffres, nbr2, n, base);
}
