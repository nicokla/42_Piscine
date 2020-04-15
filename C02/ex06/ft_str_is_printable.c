/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:55:11 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/10 15:26:12 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lettre_is_printable(char c)
{
	return (c >= 0x20 && c < 0x7f);
}

int		ft_str_is_printable(char *str)
{
	int i;
	int my_bool;

	i = 0;
	my_bool = 1;
	while (my_bool && str[i] != '\0')
	{
		my_bool = lettre_is_printable(str[i]);
		i++;
	}
	return (my_bool);
}
