/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:09:31 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:09:33 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *tmp;

	while (begin_list != NULL)
	{
		tmp = begin_list->next;
		(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}
