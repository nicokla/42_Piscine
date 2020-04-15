/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:30:48 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:30:49 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	btree_insert_data(t_btree **root, void *item,
						int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = (btree_create_node(item));
		return ;
	}
	if ((*cmpf)(item, (*root)->item) >= 0)
		btree_insert_data(&((*root)->right), item, cmpf);
	else
		btree_insert_data(&((*root)->left), item, cmpf);
}
