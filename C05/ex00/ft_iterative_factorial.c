/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:39:31 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/11 18:39:35 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int result;

	if (nb < 0)
		return (0);
	else
	{
		i = 1;
		result = 1;
		while (i <= nb)
		{
			result *= i;
			i++;
		}
		return (result);
	}
}
