/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:12:06 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 18:25:56 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lettre_is_alpha(char c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}

int		ft_str_is_alpha(char *str)
{
	int i;
	int my_bool;

	i = 0;
	my_bool = 1;
	while (my_bool && str[i] != '\0')
	{
		my_bool = lettre_is_alpha(str[i]);
		i++;
	}
	return (my_bool);
}
