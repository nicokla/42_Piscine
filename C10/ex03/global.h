/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:47:17 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 18:47:19 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define BUF_SIZE 4096
# define MODULO_SPECIAL(N) ((N % 16 == 0) ? 16 : (N % 16))
# define MAX(M,N) (M > N ? M : N)

extern char		g_buf[17];
extern char		g_buf_old[17];
extern int		g_pos_in_file;
extern int		g_pos_totale;
extern int		g_file_size;
extern int		g_last_was_same;
extern int		g_with_flag;

#endif
