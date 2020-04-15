/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:14:34 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 18:14:38 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_MEMORY_H
# define FT_PRINT_MEMORY_H

void	print_char(char c);
char	get_char_to_print(char a);
void	print_adresse(long nb_de_char, int with_flag);
void	print_line_hexa(void *addr, unsigned int size);
void	print_line_ascii(void *addr, long nb_de_char, unsigned int size);

#endif
