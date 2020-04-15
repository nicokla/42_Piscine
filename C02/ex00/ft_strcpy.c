/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:52:22 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/06/08 18:36:20 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	char* dest0 = dest;
	
	i = 0;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = *src;
	return (dest0);
}


i = 0
while src[i] != '\0'
	dest[i] = src[i]
	i++
dest[]
