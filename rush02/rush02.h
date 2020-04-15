/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:23:57 by memartin          #+#    #+#             */
/*   Updated: 2019/06/23 19:32:15 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RUSH02_H
# define _RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 100
# define MAX(N1, N2) (N1 > N2 ? N1 : N2)
# define MIN(N1, N2) (N1 < N2 ? N1 : N2)

extern char		g_buf[BUF_SIZE];
extern char		*g_units[20];
extern char		*g_decades[10];
extern char		*g_cent;
extern char		*g_thousands[13];
extern char		*g_dict[41];
extern int		g_dict_indexes[41];
extern int		g_sub_number[13];
extern int		g_last_group_of_three;

void			get_dict(int fd);
void			free_dict();
void			get_dict_aux();
int				ft_is_end_of_line(char a);
int				ft_is_space(char a);
int				ft_atoi(char *str);
int				input_is_valid();
int				get_input(int argc, char **argv);
void			copy_three_digits(char *three_digits, int i);
void			prepare_sub_number();
int				ft_strlen(char *s);
void			ft_putstr(char *s);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strdup(char *src);

#endif
