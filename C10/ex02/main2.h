/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:55:34 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/21 12:55:35 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN2_H
# define MAIN2_H

# define BUF_SIZE 4096
# define MIN(N1, N2) (N1 <= N2 ? N1 : N2)
# define MAX(N1, N2) (N1 >= N2 ? N1 : N2)

void			print_error(char *file_name, char *nom_prog);
int				calculer_taille(int *fd, char *file_name);
void			deplacer(int fd, int a);

typedef struct	s_a_and_error
{
	int		a;
	int		error;
}				t_a_and_error;

#endif
