/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:25:42 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/25 17:25:49 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_list	*ft_create_elem(char *s)
{
	t_list	*my_element;

	if ((my_element = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	my_element->s = s;
	my_element->next = NULL;
	return (my_element);
}

void	ft_list_push_front(t_list **begin_list, char *s)
{
	t_list *elmt;

	if (begin_list == 0)
		return ;
	if ((elmt = ft_create_elem(s)) == NULL)
		return ;
	elmt->next = (*begin_list);
	(*begin_list) = elmt;
}

void	ft_list_clear(t_list *begin_list)
{
	t_list *tmp;

	while (begin_list != NULL)
	{
		tmp = begin_list->next;
		free(begin_list->s);
		free(begin_list);
		begin_list = tmp;
	}
}
