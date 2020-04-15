/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:31:22 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:31:24 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>
#define MAX(A,B) (A > B ? A : B)

int		btree_level_count(t_btree *root)
{
	int a;
	int b;

	if (root == NULL)
		return (0);
	a = btree_level_count(root->left);
	b = btree_level_count(root->right);
	return (1 + MAX(a, b));
}
