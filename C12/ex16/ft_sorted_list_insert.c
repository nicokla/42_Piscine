/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:12:38 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:12:39 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*merge_recur(t_list *a, t_list *b, int (*cmp)())
{
	t_list	*result;

	if (a == 0)
		return (b);
	else if (b == 0)
		return (a);
	if ((*cmp)(a->data, b->data) <= 0)
	{
		result = a;
		result->next = merge_recur(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = merge_recur(a, b->next, cmp);
	}
	return (result);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *new_elt;

	if (begin_list == 0)
		return ;
	new_elt = ft_create_elem(data);
	*begin_list = merge_recur(*begin_list, new_elt, cmp);
}
