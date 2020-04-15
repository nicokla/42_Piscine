/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:21:07 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 19:21:09 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
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

int		get_taille_totale(int size, char **strs, int *tailles)
{
	int		i;
	int		taille_totale;

	if (size == 0)
		return (1);
	i = 0;
	taille_totale = 1;
	while (i < size)
	{
		tailles[i] = ft_strlen(strs[i]);
		taille_totale += tailles[i];
		i++;
	}
	return (taille_totale);
}

char	*ft_strcpy2(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		tailles[size];
	int		taille_totale;
	int		taille_sep;
	int		i;

	if (size == 0)
		return (ft_strdup(""));
	taille_totale =
		get_taille_totale(size, strs, tailles);
	taille_sep = ft_strlen(sep);
	taille_totale += ((size - 1) * taille_sep);
	result = malloc(taille_totale * sizeof(char));
	result[taille_totale - 1] = '\0';
	if (taille_totale == 1)
		return (result);
	result = ft_strcpy2(result, strs[0]);
	i = 1;
	while (i < size)
	{
		result = ft_strcpy2(result, sep);
		result = ft_strcpy2(result, strs[i]);
		i++;
	}
	return (result - taille_totale + 1);
}
