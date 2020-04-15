/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:12:56 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:12:57 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*merge_recur(t_list *a, t_list *b, int (*cmp)())
{
	t_list	*result;

	if (a == NULL)
		return (b);
	else if (b == NULL)
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

void	ft_sorted_list_merge(t_list **begin_list1,
							t_list *begin_list2, int (*cmp)())
{
	*begin_list1 = merge_recur(*begin_list1, begin_list2, cmp);
}
