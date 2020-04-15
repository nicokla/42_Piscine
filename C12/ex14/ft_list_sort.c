/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:11:57 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:11:59 by nklarsfe         ###   ########.fr       */
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

void	front_back_split(t_list *source,
						t_list **front_ref, t_list **back_ref)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *begin_list;
	if ((head == 0) || (head->next == 0))
		return ;
	front_back_split(head, &a, &b);
	ft_list_sort(&a, cmp);
	ft_list_sort(&b, cmp);
	*begin_list = merge_recur(a, b, cmp);
}
