/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:46:33 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/17 00:32:28 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		str1;
	int		str2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	res = (char *)malloc(str1 + str2 + 1);
	if (!res)
		return (NULL);
	while (++j < str1)
		res[j] = s1[j];
	while (++i < str2)
		res[i + j] = s2[i];
	res[i + j] = '\0';
	free(s1);
	return (res);
}
