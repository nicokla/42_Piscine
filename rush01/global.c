/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:11:53 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 11:11:58 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "global.h"

char g_all_permut[FACTORIEL_SIZE][SIZE];
Signature g_list_signatures[2][SIZE];

void	print_char(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_unsigned(int n)
{
	char	chiffres[10];
	int		i;

	i = 0;
	chiffres[0] = '0';
	while (i < 10 && n > 0)
	{
		chiffres[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (i > 0)
		i--;
	while (i >= 0)
	{
		write(1, chiffres + i, 1);
		i--;
	}
}
