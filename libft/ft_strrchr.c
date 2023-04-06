/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:48:18 by mochaoui          #+#    #+#             */
/*   Updated: 2023/03/25 14:46:57 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	while (a > 0)
	{
		if (str[a] == (unsigned char)c)
			return ((char *)&str[a]);
		a--;
	}
	if (str[a] == (unsigned char)c)
		return ((char *)&str[a]);
	return (NULL);
}
