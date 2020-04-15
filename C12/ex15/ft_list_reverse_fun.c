/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:12:20 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:12:21 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	void	*tmp_data;

	if (begin_list == 0)
		return ;
	if (begin_list->next == 0)
		return ;
	tmp = begin_list->next;
	ft_list_reverse_fun(tmp);
	tmp = begin_list;
	while (tmp->next != 0)
	{
		tmp_data = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = tmp_data;
		tmp = tmp->next;
	}
}
