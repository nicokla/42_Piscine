/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:58:46 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/11 21:58:48 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string(char **tab, int size)
{
	int		i;
	int		j;
	char	*x;

	i = 1;
	while (i < size)
	{
		x = tab[i];
		j = i;
		while (j > 0 && ft_strcmp(tab[j - 1], x) > 0)
		{
			ft_swap(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	ft_sort_string(argv + 1, argc - 1);
	i = 1;
	while (i <= (argc - 1))
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}
