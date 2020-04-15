/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:07:37 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:07:40 by nklarsfe         ###   ########.fr       */
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
