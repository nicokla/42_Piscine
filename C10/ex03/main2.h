/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:01:49 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 19:01:52 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN2_H
# define MAIN2_H

int		reopen(int fd, char *buf, char *file_name);
int		calculer_taille(int *p_fd, char *file_name);
void	print_error(char *file_name, char *nom_prog);
void	print_line_all(void);

#endif
