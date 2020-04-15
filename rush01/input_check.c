/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:46:37 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 12:48:00 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "global.h"

int		is_good(int argc, char **argv)
{
	if (argc == 2)
		return (ft_strlen(argv[1]) >= ((8 * SIZE) - 1));
	else
		return (0);
}

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		is_petit_chiffre(char n)
{
	return (n >= 0 && n <= 9);
}

int		is_good2(Signature *g_list_signatures_c,
				Signature *g_list_signatures_l)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		if (!(is_petit_chiffre(g_list_signatures_c[0].s[i])
			&& is_petit_chiffre(g_list_signatures_c[1].s[i])
			&& is_petit_chiffre(g_list_signatures_l[0].s[i])
			&& is_petit_chiffre(g_list_signatures_l[1].s[i])))
			return (0);
		i++;
	}
	return (1);
}
