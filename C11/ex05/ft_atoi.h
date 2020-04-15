/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:56:13 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/19 11:56:15 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H

int		ft_isspace(char a);
int		avancer_space(char **pstr, int *psigne, long *pres);
int		avancer_signes(char **pstr, int *psigne, long *pres);
int		avancer_num(char **pstr, int *psigne, long *pres);
int		ft_atoi(char *str);

#endif
