/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:27:52 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 18:38:41 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lettre_is_numeric(char c)
{
	return (c >= 48 && c <= 57);
}

int		ft_str_is_numeric(char *str)
{
	int i;
	int my_bool;

	i = 0;
	my_bool = 1;
	while (my_bool && str[i] != '\0')
	{
		my_bool = lettre_is_numeric(str[i]);
		i++;
	}
	return (my_bool);
}
