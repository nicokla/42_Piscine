/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:03:26 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/13 17:03:30 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	calculer_nombre(char *str, long *pres, char *base, int n)
{
	int chiffre;
	int str_length;
	int i;

	str_length = ft_strlen(str);
	i = 0;
	while (i < str_length)
	{
		chiffre = 0;
		while (base[chiffre] != str[i] && chiffre < n)
			chiffre++;
		if (chiffre != n)
		{
			*pres *= n;
			*pres += chiffre;
		}
		else
			break ;
		i++;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	long	res;
	int		signe;
	int		i;
	int		length_str;

	res = 0;
	signe = 1;
	if (!base_est_ok(base, ft_strlen(base)))
		return (0);
	i = 0;
	length_str = ft_strlen(str);
	while (i < length_str && ft_isspace(str[i]))
		i++;
	while (i < length_str && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			signe *= (-1);
		i++;
	}
	calculer_nombre(str + i, &res, base, ft_strlen(base));
	return ((int)res * signe);
}
