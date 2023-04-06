/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:30:29 by mochaoui          #+#    #+#             */
/*   Updated: 2022/10/22 19:15:02 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	b;
	char	*r;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	r = (char *)malloc(sizeof(char) * len + 1);
	if (!r)
		return (NULL);
	a = 0;
	b = 0;
	while (s[a])
	{
		if (a >= start && b < len)
			r[b++] = s[a];
		a++;
	}
	r[b] = '\0';
	return (r);
}
