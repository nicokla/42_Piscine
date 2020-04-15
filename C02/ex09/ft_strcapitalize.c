/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:18:40 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 19:52:13 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha_num(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

void	capitalize_if_needed(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str = *str - 32;
	}
}

void	minimalize(char *str)
{
	*str = *str + 32;
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int should_be_capitalized;

	i = 0;
	should_be_capitalized = 1;
	while (str[i] != '\0' && i < 1000000)
	{
		if (should_be_capitalized)
		{
			capitalize_if_needed(str + i);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			minimalize(str + i);
		}
		i++;
		should_be_capitalized = is_alpha_num(str[i])
			&& !is_alpha_num(str[i - 1]);
	}
	return (str);
}
