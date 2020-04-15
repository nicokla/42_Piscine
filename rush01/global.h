/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcany <pcany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:14:34 by pcany             #+#    #+#             */
/*   Updated: 2019/06/16 12:51:44 by pcany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GLOBAL_H
#define		GLOBAL_H

#define		SIZE				4
#define		FACTORIEL_SIZE		24

typedef struct		permut_ {
	char p[SIZE];
} Permutation;

typedef struct		sig_ {
	int s[2];
} Signature;

typedef struct		tableau_ {
	char t[SIZE][SIZE];
} Tableau;

extern char 		g_all_permut[FACTORIEL_SIZE][SIZE];
extern Signature 	g_list_signatures[2][SIZE];

void				print_char(char c);
int					ft_strlen(char *s);
void				ft_putnbr_unsigned(int n);


#endif
