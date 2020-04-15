/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:58:14 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 18:58:19 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lettre_is_lowercase(char c)
{
	return (c >= 97 && c <= 122);
}

int		ft_str_is_lowercase(char *str)
{
	int i;
	int my_bool;

	i = 0;
	my_bool = 1;
	while (my_bool && str[i] != '\0')
	{
		my_bool = lettre_is_lowercase(str[i]);
		i++;
	}
	return (my_bool);
}
