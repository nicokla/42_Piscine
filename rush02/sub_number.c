/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sous_nombres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:17:32 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:32:16 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	copy_three_digits(char *three_digits, int i)
{
	three_digits[2] = g_buf[i];
	if (i - 1 >= 0)
		three_digits[1] = g_buf[i - 1];
	else
		three_digits[1] = ' ';
	if (i - 2 >= 0)
		three_digits[0] = g_buf[i - 2];
	else
		three_digits[0] = ' ';
}

void	prepare_sub_number(void)
{
	int		i;
	char	three_digits[4];
	int		k;

	three_digits[3] = '\0';
	i = ft_strlen(g_buf);
	i--;
	k = 0;
	while (i >= 0 && k <= 12)
	{
		copy_three_digits(three_digits, i);
		g_sub_number[k] = ft_atoi(three_digits);
		i -= 3;
		k++;
	}
	k--;
	g_last_group_of_three = k;
}
