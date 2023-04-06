/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:46:33 by mochaoui          #+#    #+#             */
/*   Updated: 2022/10/22 19:12:32 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		on;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	on = ft_strlen(s1);
	string = (char *)malloc(sizeof(char) * on + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		string[a] = s1[a];
		a++;
	}
	a = 0;
	while (s2[a])
		string[on++] = s2[a++];
	string[on] = '\0';
	return (string);
}
