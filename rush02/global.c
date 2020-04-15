/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:49:02 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/23 19:32:02 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	g_buf[BUF_SIZE];
char	*g_units[20];
char	*g_decades[10];
char	*g_cent;
char	*g_thousands[13];
char	*g_dict[41];
int		g_dict_indexes[41];
int		g_sub_number[13];
int		g_last_group_of_three;
