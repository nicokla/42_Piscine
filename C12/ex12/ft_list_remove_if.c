/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:11:23 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:11:24 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*delete_elt(t_list *before, t_list *current,
					void (*free_fct)(void *))
{
	t_list *next;

	if (current != 0)
	{
		next = current->next;
		if (before != 0)
			before->next = next;
		if (current->data != 0)
			(*free_fct)(current->data);
		free(current);
		return (next);
	}
	return (0);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*before;
	t_list	*current;
	t_list	*tmp;

	if (begin_list == 0)
		return ;
	before = 0;
	current = *begin_list;
	while (current != 0)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			tmp = delete_elt(before, current, free_fct);
			if (before == 0)
				*begin_list = tmp;
			current = tmp;
		}
		else
		{
			before = current;
			current = current->next;
		}
	}
}
