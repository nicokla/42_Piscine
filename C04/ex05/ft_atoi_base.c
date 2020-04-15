/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:17:30 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/13 11:48:36 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		is_space(char a)
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

int		base_est_ok(char *base, int n)
{
	int i;
	int j;

	i = 0;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
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

	while (1)
	{
		chiffre = 0;
		while (base[chiffre] != (*str) && chiffre < n)
		{
			chiffre++;
		}
		if (chiffre != n)
		{
			*pres *= n;
			*pres += chiffre;
		}
		else
			break ;
		str++;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	long	res;
	int		signe;
	int		i;
	int		n;

	res = 0;
	signe = 1;
	n = ft_strlen(base);
	if (!base_est_ok(base, n))
		return (0);
	i = 0;
	while (is_space(str[i]) && i < n)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= (-1);
		i++;
	}
	calculer_nombre(str + i, &res, base, n);
	return ((int)res * signe);
}
