/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:21:22 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/12 19:21:23 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_est_ok(char *base, int n);
int		ft_strlen(char *str);
int		ft_isspace(char a);
int		ft_atoi_base(char *str, char *base);
void	calculer_nombre(char *str, long *pres, char *base, int n);

char	*ft_strdup_char(char src)
{
	char	*p;

	if (src == '\0')
	{
		p = malloc(sizeof(char));
		p[0] = '\0';
	}
	else
	{
		p = malloc(sizeof(char) * 2);
		p[0] = src;
		p[1] = '\0';
	}
	return (p);
}

void	calculer_chiffres(long *chiffres, long nbr,
						char *base, int *p_nb_chiffres)
{
	int		i;
	long	n;

	if (nbr < 0)
	{
		nbr = (-nbr);
	}
	n = (long)ft_strlen(base);
	i = 0;
	while (nbr > 0 && i <= 32)
	{
		chiffres[i] = (nbr % n);
		nbr /= n;
		i++;
	}
	(*p_nb_chiffres) = i;
}

int		malloc_answers(char **p_answer, int nb_chiffres, long nbr)
{
	int debut;

	if (nbr >= 0)
	{
		(*p_answer) = malloc(sizeof(char) * (nb_chiffres + 1));
		debut = 0;
	}
	else
	{
		(*p_answer) = malloc(sizeof(char) * (nb_chiffres + 2));
		debut = 1;
		(*p_answer)[0] = '-';
	}
	return (debut);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	chiffres[33];
	char	*answer;
	int		nb_chiffres;
	int		debut;

	if (!base_est_ok(base, ft_strlen(base)))
	{
		answer = malloc(sizeof(*answer));
		*answer = '\0';
		return (answer);
	}
	if (nbr == 0)
		return (ft_strdup_char(base[0]));
	calculer_chiffres(chiffres, (long)nbr, base, &nb_chiffres);
	debut = malloc_answers(&answer, nb_chiffres, (long)nbr);
	i = 0;
	while (i < nb_chiffres)
	{
		answer[debut + i] = base[(int)(chiffres[nb_chiffres - 1 - i])];
		i++;
	}
	answer[debut + i] = '\0';
	return (answer);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*answer;

	if (!base_est_ok(base_from, ft_strlen(base_from))
		|| !base_est_ok(base_to, ft_strlen(base_to)))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	answer = ft_putnbr_base(n, base_to);
	return (answer);
}
