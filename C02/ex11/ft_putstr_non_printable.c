/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:34:09 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 20:41:57 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char c)
{
	return (c >= 0x20 && c < 0x7f);
}

void	print(char c)
{
	write(1, &c, 1);
}

void	print_hexa(unsigned char c)
{
	unsigned char	n[2];
	int				i;

	print('\\');
	n[0] = c / 16;
	n[1] = c % 16;
	i = 0;
	while (i < 2)
	{
		if (n[i] < 10)
		{
			print(n[i] + 48);
		}
		else
		{
			print(n[i] + 97 - 10);
		}
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < 100000)
	{
		if (is_printable(str[i]))
		{
			print(str[i]);
		}
		else
		{
			print_hexa((unsigned char)str[i]);
		}
		i++;
	}
}
