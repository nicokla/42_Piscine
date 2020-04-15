/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:19:51 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 13:21:03 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

t_btree			*btree_create_node(void *item);

typedef struct	s_elt
{
	t_btree			*tree_node;
	int				depth;
	struct s_elt	*suivant;
}				t_elt;

typedef struct	s_file
{
	t_elt	*premier;
}				t_file;

#endif
