/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:31:42 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:31:43 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>
#define MAX(A,B) (A > B ? A : B)

void		enfiler(t_file *file, t_btree *tree_node,
					int depth)
{
	t_elt *element_actuel;
	t_elt *nouveau;

	nouveau = malloc(sizeof(*nouveau));
	if (file == NULL || nouveau == NULL)
		return ;
	nouveau->tree_node = tree_node;
	nouveau->depth = depth;
	nouveau->suivant = NULL;
	if (file->premier != NULL)
	{
		element_actuel = file->premier;
		while (element_actuel->suivant != NULL)
			element_actuel = element_actuel->suivant;
		element_actuel->suivant = nouveau;
	}
	else
		file->premier = nouveau;
}

t_elt		*defiler(t_file *file)
{
	t_elt		*element_defile;

	if (file == NULL)
		return (NULL);
	element_defile = NULL;
	if (file->premier != NULL)
	{
		element_defile = file->premier;
		file->premier = element_defile->suivant;
	}
	return (element_defile);
}

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
							int current_level, int is_first_elem))
{
	t_file	fifo;
	int		max_depth;
	t_elt	*n;
	int		first;

	max_depth = (-1);
	fifo.premier = NULL;
	enfiler(&fifo, root, 0);
	while (!(fifo.premier == NULL))
	{
		n = defiler(&fifo);
		first = (n->depth > max_depth);
		max_depth = MAX(max_depth, n->depth);
		(*applyf)(n->tree_node, n->depth, first);
		if (n->tree_node->left != NULL)
			enfiler(&fifo, n->tree_node->left, n->depth + 1);
		if (n->tree_node->right != NULL)
			enfiler(&fifo, n->tree_node->right, n->depth + 1);
		free(n);
	}
}
