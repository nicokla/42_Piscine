/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:47:12 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 12:47:33 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CHECK_H
#define INPUT_CHECK_H

#include "global.h"

int		is_good(int argc, char **argv);
int		print_error();
int		is_petit_chiffre(char n);
int		is_good2(Signature *list_sig_c, Signature *list_sig_l);

#endif
