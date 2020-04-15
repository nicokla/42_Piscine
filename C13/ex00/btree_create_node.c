/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:29:34 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:29:36 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	if ((tree = malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	tree->left = NULL;
	tree->right = NULL;
	tree->item = item;
	return (tree);
}
