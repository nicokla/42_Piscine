/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:08:50 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:08:52 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *old_elt;
	t_list *last_el;
	t_list *current;

	if (begin_list == 0)
		return ;
	current = *begin_list;
	last_el = ft_create_elem(data);
	old_elt = 0;
	while (current != 0)
	{
		old_elt = current;
		current = current->next;
	}
	if (old_elt != 0)
		old_elt->next = last_el;
	else
		(*begin_list) = last_el;
}
