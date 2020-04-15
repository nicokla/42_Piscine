/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:09:56 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/25 23:20:19 by ale-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 100
# define MAX(N1, N2) (N1 > N2 ? N1 : N2)
# define MIN(N1, N2) (N1 < N2 ? N1 : N2)

typedef	struct	s_list
{
	struct s_list	*next;
	char			*s;
}				t_list;

typedef	struct	s_input
{
	int		nb_lines;
	int		nb_columns;
	char	*carte;
	char	case_vide;
	char	case_obstacle;
	char	case_carre;
}				t_input;

typedef	struct	s_output
{
	int		*tab;
	int		max;
	int		i0;
	int		j0;
}				t_output;

int				ft_strlen(char *s);
void			ft_putstr(char *s);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
void			solve(t_input *p_input, t_output *p_output);
int				get_input_v1(t_input *p_input, int fd);
void			print(t_input *p_input);
void			free_all(t_input *p_input, t_output *p_output);
int				get_input(t_input *p_input, int fd);
void			print_2(t_input *p_input, t_output *p_output);
t_list			*ft_create_elem(char *s);
void			ft_list_push_front(t_list **begin_list, char *s);
void			ft_list_clear(t_list *begin_list);
void			debug(char *message, int a, int i, int j,
				char c, char *s);
void			mettre_carre(t_input *p_input, t_output *p_output);
int				get_nb_lignes_and_symbols(t_input *p_input, int fd);
int				compute_nb_columns(t_input *ppp, int fd,
									int *pi, t_list **p_elt);

#endif
