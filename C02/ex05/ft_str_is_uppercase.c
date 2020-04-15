/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:58:26 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 18:58:28 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lettre_is_uppercase(char c)
{
	return (c >= 65 && c <= 90);
}

int		ft_str_is_uppercase(char *str)
{
	int i;
	int my_bool;

	i = 0;
	my_bool = 1;
	while (my_bool && str[i] != '\0')
	{
		my_bool = lettre_is_uppercase(str[i]);
		i++;
	}
	return (my_bool);
}
