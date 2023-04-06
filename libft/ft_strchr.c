/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:49:32 by mochaoui          #+#    #+#             */
/*   Updated: 2023/03/25 14:47:26 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = 0;
	while (s[a])
	{
		if ((unsigned char)s[a] == (unsigned char)c)
			return ((char *)s + a);
		a++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s + a);
	return (NULL);
}
