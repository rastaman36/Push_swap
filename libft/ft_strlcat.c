/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:37:02 by mochaoui          #+#    #+#             */
/*   Updated: 2022/10/26 23:03:53 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!dst && dstsize == 0)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(dst);
	if (len >= dstsize)
		return (ft_strlen(src) + dstsize);
	else
	{
		while (dst[i])
			i++;
		k = (ft_strlen(dst) + ft_strlen(src));
		while (src[j] && (i < dstsize - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (k);
}
