/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:31:07 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/27 16:44:32 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	void *tmp;

	if (root == NULL)
		return (NULL);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp != NULL)
		return (tmp);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	tmp = btree_search_item(root->right, data_ref, cmpf);
	if (tmp != NULL)
		return (tmp);
	return (NULL);
}
