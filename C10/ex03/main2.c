/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:47:26 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/20 18:47:27 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "ft_print_memory.h"
#include "global.h"
#include "main2.h"

int		reopen(int fd, char *buf, char *file_name)
{
	if (close(fd) == -1)
	{
		free(buf);
		return (1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (1);
	}
	return (fd);
}

int		calculer_taille(int *p_fd, char *file_name)
{
	int		taille;
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * BUF_SIZE);
	taille = 0;
	ret = read(*p_fd, buf, BUF_SIZE);
	while (ret != 0 && ret != (-1))
	{
		taille += ret;
		ret = read(*p_fd, buf, BUF_SIZE);
	}
	(*p_fd) = reopen(*p_fd, buf, file_name);
	if (*p_fd == 1)
		return (-1);
	free(buf);
	return (taille);
}

void	print_error(char *file_name, char *nom_prog)
{
	ft_putstr_err(basename(nom_prog));
	ft_putstr_err(": ");
	ft_putstr_err(file_name);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
}

void	print_line_all(void)
{
	int decalage;

	decalage = MODULO_SPECIAL(g_pos_totale);
	if (ft_strncmp(g_buf, g_buf_old, 16) != 0
		|| decalage != 16)
	{
		print_adresse(g_pos_totale - decalage, g_with_flag);
		print_line_hexa(g_buf, decalage);
		if (g_with_flag)
			print_line_ascii(g_buf, 0, decalage);
		ft_strncpy(g_buf_old, g_buf, 16);
		g_last_was_same = 0;
	}
	else if (!g_last_was_same)
	{
		ft_putstr("*\n");
		g_last_was_same = 1;
	}
}
