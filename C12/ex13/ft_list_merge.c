/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:11:41 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:11:42 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *old_elt;

	old_elt = 0;
	while (begin_list != 0)
	{
		old_elt = begin_list;
		begin_list = begin_list->next;
	}
	return (old_elt);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *elt;

	if (begin_list1 == 0 || begin_list2 == 0)
		return ;
	elt = ft_list_last(*begin_list1);
	if (elt != 0)
		elt->next = begin_list2;
	else
		(*begin_list1) = begin_list2;
}
