/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:04:51 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 23:55:06 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "global.h"

void			print_char(char c)
{
	if (c >= 32 && c < 127)
		write(1, &c, 1);
	else
	{
		c = '.';
		write(1, &c, 1);
	}
}

unsigned char	get_char_to_print(unsigned char a)
{
	char result;

	if (a <= 9)
		result = a + 48;
	else
		result = a + 87;
	return (result);
}

void			print_adresse(long nb_de_char, int with_flag)
{
	int		i;
	char	tab[15];

	i = 0;
	while (i < 8 - 1 + (with_flag % 2))
	{
		tab[i] = get_char_to_print(nb_de_char % 16);
		nb_de_char = nb_de_char / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		print_char(tab[i]);
	}
	if (with_flag == 1)
		write(1, "  ", 2);
	else if (with_flag == 0)
		write(1, " ", 1);
}

void			print_line_hexa(void *addr,
						unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			print_char(get_char_to_print(
				*((unsigned char*)((long)addr + i)) / 16));
			print_char(get_char_to_print(
				*((unsigned char*)((long)addr + i)) % 16));
		}
		else
			write(1, "  ", 2);
		if (i % 8 == 7 && g_with_flag)
			write(1, "  ", 2);
		else if (g_with_flag)
			write(1, " ", 1);
		else if (i < 15)
			write(1, " ", 1);
		i++;
	}
	if (!g_with_flag)
		write(1, "\n", 1);
}

void			print_line_ascii(void *addr,
					long nb_de_char, unsigned int size)
{
	int		i;

	i = 0;
	write(1, "|", 1);
	while (i < 16 && nb_de_char < size)
	{
		print_char(*((char*)((long)addr + nb_de_char)));
		nb_de_char++;
		i++;
	}
	write(1, "|\n", 2);
}
