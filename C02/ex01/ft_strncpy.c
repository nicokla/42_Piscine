/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:19:37 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 18:01:08 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
	int n2;

	n2 = (int)n;
	i = 0;
	while (src[i] != '\0' && i < n2)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n2)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
