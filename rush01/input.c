/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:14:40 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 12:46:54 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "global.h"

void	get_signatures(char *s)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		g_list_signatures[0][i].s[0] = s[2 * i] - '0';
		i++;
	}
	while (i < (2 * SIZE))
	{
		g_list_signatures[0][i - SIZE].s[1] = s[2 * i] - '0';
		i++;
	}
	while (i < (3 * SIZE))
	{
		g_list_signatures[1][i - 2 * SIZE].s[0] = s[2 * i] - '0';
		i++;
	}
	while (i < (4 * SIZE))
	{
		g_list_signatures[1][i - 3 * SIZE].s[1] = s[2 * i] - '0';
		i++;
	}
}
