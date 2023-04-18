/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:21:49 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/18 02:47:08 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strjoin2(char const *s1, char const *s2)
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

void	*ft_memset(void *d, int c, size_t n)
{
	size_t			a;
	unsigned char	*w;

	w = (unsigned char *)d;
	a = 0;
	while (a < n)
	{
		w[a] = c;
		a++;
	}
	return (d);
}

void	*ft_calloc2(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
