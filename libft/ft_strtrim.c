/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:47:31 by mochaoui          #+#    #+#             */
/*   Updated: 2023/03/25 14:47:03 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ln;
	size_t	a;

	a = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[a] && ft_strchr(set, s1[a]))
		a++;
	ln = ft_strlen(s1);
	while (ln > a && ft_strrchr(set, s1[ln]))
		ln--;
	return (ft_substr(s1, a, ln - a + 1));
}
