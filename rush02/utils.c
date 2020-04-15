/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:25:15 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:13:26 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int				ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
}

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return ((int)(s1[i]) - (int)(s2[i]));
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int vrai_taille;

	i = 0;
	while (src[i] != '\0' && (i + 1) < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0' && i < 1000000)
	{
		i++;
	}
	vrai_taille = i;
	return (vrai_taille);
}

char			*ft_strdup(char *src)
{
	char	*p;
	int		i;
	int		n;

	n = ft_strlen(src);
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
