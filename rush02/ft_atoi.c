/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:44:27 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:13:34 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_is_end_of_line(char a)
{
	int answer;

	answer = (a == '\n')
		|| (a == 10);
	return (answer);
}

int		ft_is_space(char a)
{
	int answer;

	answer = (a == ' ')
		|| (a == 32);
	return (answer);
}

void	calc_number(char *str, long *pres)
{
	int digit;

	while (1)
	{
		digit = (*str) - '0';
		if (digit <= 9 && digit >= 0)
		{
			*pres *= 10;
			*pres += digit;
		}
		else
			break ;
		str++;
	}
}

int		ft_atoi(char *str)
{
	long	res;
	long	signe;
	int		i;
	int		length_str;

	length_str = ft_strlen(str);
	res = 0;
	signe = 1;
	i = 0;
	while (ft_is_space(str[i]) && i < length_str)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= (-1);
		i++;
	}
	calc_number(str + i, &res);
	return ((int)(res * signe));
}
