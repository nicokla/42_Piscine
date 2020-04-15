/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:40:52 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/19 11:40:54 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		plus(int a, int b)
{
	return (a + b);
}

int		moins(int a, int b)
{
	return (a - b);
}

int		mult(int a, int b)
{
	return (a * b);
}

int		div(int a, int b)
{
	if (b != 0)
		return (a / b);
	return (0);
}

int		modulo(int a, int b)
{
	if (b != 0)
		return (a % b);
	return (0);
}
