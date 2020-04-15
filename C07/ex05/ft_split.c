/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:21:35 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 19:21:36 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup2(char *src, int n)
{
	char	*p;
	int		i;

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

int		is_normal(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int		compter_mots(char *str, char *charset)
{
	int i;
	int last_char_is_normal;
	int answer;

	answer = 0;
	last_char_is_normal = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_normal(str[i], charset)
			&& !last_char_is_normal)
			answer++;
		last_char_is_normal =
			is_normal(str[i], charset);
		i++;
	}
	return (answer);
}

void	main_loop(char *str, char *charset, char **debuts, int *tailles)
{
	int		indice_mots;
	int		nb_mots;
	int		last_was_normal;
	int		i;

	nb_mots = compter_mots(str, charset);
	indice_mots = 0;
	last_was_normal = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!last_was_normal && is_normal(str[i], charset))
		{
			debuts[indice_mots] = str + i;
			tailles[indice_mots] = 1;
		}
		if (last_was_normal && is_normal(str[i], charset))
			tailles[indice_mots]++;
		else if (last_was_normal && !is_normal(str[i], charset))
			indice_mots++;
		last_was_normal = is_normal(str[i], charset);
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		nb_mots;
	char	**answer;
	char	**debuts;
	int		*tailles;

	nb_mots = compter_mots(str, charset);
	debuts = malloc(sizeof(*debuts) * (1 + nb_mots));
	tailles = malloc(sizeof(*tailles) * (1 + nb_mots));
	main_loop(str, charset, debuts, tailles);
	answer = malloc(sizeof(*answer) * (1 + nb_mots));
	i = 0;
	while (i < nb_mots)
	{
		answer[i] = ft_strdup2(debuts[i], tailles[i]);
		i++;
	}
	answer[nb_mots] = NULL;
	return (answer);
}
