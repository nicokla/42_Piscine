/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:55:26 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/21 12:55:27 by nklarsfe         ###   ########.fr       */
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
#include "utils.h"
#include "ft_atoi.h"
#include "main2.h"

void	print_error(char *file_name, char *nom_prog)
{
	ft_putstr_err(basename(nom_prog));
	ft_putstr_err(": ");
	ft_putstr_err(file_name);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
}

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

int		calculer_taille(int *fd, char *file_name)
{
	int		taille;
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * BUF_SIZE);
	taille = 0;
	while ((ret = read(*fd, buf, BUF_SIZE)) > 0)
		taille += ret;
	(*fd) = reopen(*fd, buf, file_name);
	if (*fd == 1)
		return (-1);
	free(buf);
	return (taille);
}

void	deplacer(int fd, int a)
{
	int		restant;
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * BUF_SIZE);
	restant = a;
	ret = read(fd, buf, MIN(BUF_SIZE, restant));
	while (ret != 0 && ret != (-1) && restant > 0)
	{
		restant -= ret;
		ret = read(fd, buf, MIN(BUF_SIZE, restant));
	}
	free(buf);
}
