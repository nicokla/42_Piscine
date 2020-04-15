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

void	print_char(char c)
{
	if (c >= 32)
	{
		write(1, &c, 1);
	}
	else
	{
		c = '.';
		write(1, &c, 1);
	}
}

char	get_char_to_print(char a)
{
	char result;

	if (a <= 9)
	{
		result = a + 48;
	}
	else
	{
		result = a + 87;
	}
	return (result);
}

void	print_adresse(long addr)
{
	int		i;
	char	tab[15];

	i = 0;
	while (i < 15)
	{
		tab[i] = get_char_to_print(addr % 16);
		addr = addr / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		print_char(tab[i]);
	}
	print_char(':');
	print_char(' ');
}

void	print_line_hexa(void *addr, long *p_nb_de_char, unsigned int size)
{
	int i;

	i = 0;
	while (i < 16 && (*p_nb_de_char) < size)
	{
		print_char(get_char_to_print(
			*((char*)((long)addr + *p_nb_de_char)) / 16));
		print_char(get_char_to_print(
			*((char*)((long)addr + *p_nb_de_char)) % 16));
		if (i % 2 == 1)
		{
			print_char(' ');
		}
		i++;
		(*p_nb_de_char)++;
	}
	print_char(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long	nb_de_char;
	long	nb_de_char_old;
	char	new_line;
	int		i;

	new_line = '\n';
	nb_de_char = 0;
	while (nb_de_char < size)
	{
		print_adresse((long)addr + nb_de_char);
		nb_de_char_old = nb_de_char;
		print_line_hexa(addr, &nb_de_char, size);
		nb_de_char = nb_de_char_old;
		i = 0;
		while (i < 16 && nb_de_char < size)
		{
			print_char(*((char*)((long)addr + nb_de_char)));
			nb_de_char++;
			i++;
		}
		write(1, &new_line, 1);
	}
	return (addr);
}
