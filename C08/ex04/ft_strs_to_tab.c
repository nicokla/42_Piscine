/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:34:10 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 19:34:12 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen2(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*p;
	int		i;
	int		n;

	n = ft_strlen2(src);
	p = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i <= n)
	{
		p[i] = src[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	result = malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen2(av[i]);
		result[i].str = ft_strdup(av[i]);
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[ac].size = -1;
	result[ac].str = NULL;
	result[ac].copy = NULL;
	return (result);
}
