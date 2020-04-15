/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:17:07 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/10 23:28:25 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sous_fonction(char *chiffres, int n, int i)
{
	i = 0;
	while (i < 10 && n > 0)
	{
		chiffres[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (i > 0)
	{
		i--;
	}
	while (i >= 0)
	{
		write(1, chiffres + i, 1);
		i--;
	}
}

void	ft_putnbr(int n)
{
	char	chiffres[10];
	int		i;

	i = 0;
	chiffres[0] = 48;
	if (n < 0)
	{
		ft_putchar('-');
		if (n != -2147483648)
		{
			n = -n;
		}
		else
		{
			sous_fonction(chiffres, 214748364, i);
			ft_putchar('8');
			return ;
		}
	}
	sous_fonction(chiffres, n, i);
}
