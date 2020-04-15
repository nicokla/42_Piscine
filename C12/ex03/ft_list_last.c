/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:08:26 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:08:29 by nklarsfe         ###   ########.fr       */
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
