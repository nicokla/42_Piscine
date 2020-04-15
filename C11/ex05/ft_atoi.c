/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:17:14 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/11 14:36:50 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char a)
{
	int answer;

	answer = (a == ' ')
		|| (a == '\n')
		|| (a == '\t')
		|| (a == '\v')
		|| (a == '\f')
		|| (a == '\r');
	return (answer);
}

int		avancer_space(char **pstr, int *psigne, long *pres)
{
	psigne += 1;
	pres += 1;
	if (ft_isspace(**pstr))
	{
		(*pstr)++;
		return (0);
	}
	else if (**pstr == '+'
		|| **pstr == '-'
		|| (**pstr <= '9' && **pstr >= '0'))
		return (1);
	else
		return (2);
}

int		avancer_signes(char **pstr, int *psigne, long *pres)
{
	pres += 1;
	if (**pstr == '+'
		|| **pstr == '-')
	{
		if (**pstr == '-')
			(*psigne) *= (-1);
		(*pstr)++;
		return (0);
	}
	else if (**pstr <= '9' && **pstr >= '0')
		return (1);
	else
		return (2);
}

int		avancer_num(char **pstr, int *psigne, long *pres)
{
	psigne += 1;
	if (**pstr <= '9' && **pstr >= '0')
	{
		*pres *= 10;
		*pres += (**pstr - '0');
		(*pstr)++;
		return (0);
	}
	else
		return (2);
}

int		ft_atoi(char *str)
{
	long	res;
	int		signe;
	int		should_change_sthg;
	int		(*pf[3])(char **, int *, long *);
	int		n_fonc;

	pf[0] = avancer_space;
	pf[1] = avancer_signes;
	pf[2] = avancer_num;
	n_fonc = 0;
	res = 0;
	signe = 1;
	should_change_sthg = 0;
	while (1)
	{
		should_change_sthg =
			(*pf[n_fonc])(&str, &signe, &res);
		if (should_change_sthg == 1)
			n_fonc++;
		else if (should_change_sthg == 2)
			return ((int)res * signe);
	}
	return (0);
}
