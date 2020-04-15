/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:30:34 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/25 17:30:36 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	traite_file(t_input *p_input, t_output *p_output, int fd)
{
	int error;

	if (fd == -1)
		error = 1;
	else
		error = get_input(p_input, fd);
	if (error)
	{
		write(2, "map error\n", 10);
		return ;
	}
	solve(p_input, p_output);
	print(p_input);
	free_all(p_input, p_output);
}

int		main(int argc, char **argv)
{
	t_input		input;
	t_output	output;
	int			i;
	int			fd;

	if (argc == 1)
		traite_file(&input, &output, STDIN_FILENO);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			traite_file(&input, &output, fd);
			close(fd);
			if (i != (argc - 1))
				write(1, "\n", 1);
			i++;
		}
	}
}
