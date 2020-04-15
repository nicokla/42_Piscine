/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:09:10 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:09:12 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *elmt;

	if (begin_list == 0)
		return ;
	elmt = ft_create_elem(data);
	elmt->next = (*begin_list);
	(*begin_list) = elmt;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*elt;
	int		i;

	i = 0;
	elt = 0;
	while (i < size)
	{
		ft_list_push_front(&elt, strs[i]);
		i++;
	}
	return (elt);
}
