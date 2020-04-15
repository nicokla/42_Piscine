/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:07:03 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:07:10 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*my_element;

	my_element = malloc(sizeof(t_list));
	if (my_element == NULL)
		return (NULL);
	my_element->data = data;
	my_element->next = NULL;
	return (my_element);
}
