/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:10:07 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:10:09 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*elt1;
	t_list	*elt2;
	t_list	*tmp;

	if (begin_list == 0)
		return ;
	if (*begin_list == 0)
		return ;
	elt1 = *begin_list;
	elt2 = elt1->next;
	elt1->next = 0;
	while (elt2 != 0)
	{
		tmp = elt2->next;
		elt2->next = elt1;
		elt1 = elt2;
		elt2 = tmp;
	}
	*begin_list = elt1;
}
