/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:01:03 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/18 02:47:26 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_and_free(char *buffer, char *clean)
{
	char	*result;

	result = ft_strjoin2(buffer, clean);
	free(buffer);
	return (result);
}

char	*check_rest(char *string)
{
	char	*save;
	int		index1;
	int		index2;

	index1 = 0;
	index2 = 0;
	while (string[index1] && string[index1] != '\n')
		index1++;
	if (!string[index1])
	{
		free(string);
		return (NULL);
	}
	save = ft_calloc2((ft_strlen(string) - index1 + 1), sizeof(char));
	index1++;
	while (string[index1])
		save[index2++] = string[index1++];
	free(string);
	return (save);
}

char	*checking_line(char *string)
{
	int		a;
	char	*clear;

	a = 0;
	if (!string[a])
		return (NULL);
	while (string[a] && string[a] != '\n')
		a++;
	clear = ft_calloc2(a + 2, sizeof(char));
	a = 0;
	while (string[a] && string[a] != '\n')
	{
		clear[a] = string[a];
		a++;
	}
	if (string[a] && string[a] == '\n')
		clear[a++] = '\n';
	return (clear);
}

char	*readingfile(int fd, char *result)
{
	int		reading_byte;
	char	*buff;

	reading_byte = 1;
	if (!result)
		result = ft_calloc2(1, 1);
	buff = ft_calloc2(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(result, '\n') && reading_byte != 0)
	{
		reading_byte = read(fd, buff, BUFFER_SIZE);
		if (reading_byte == -1)
		{
			free(result);
			free(buff);
			return (NULL);
		}
		buff[reading_byte] = '\0';
		result = join_and_free(result, buff);
	}
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*dreal;
	static char	*get_info;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	get_info = readingfile(fd, get_info);
	if (!get_info)
		return (NULL);
	dreal = checking_line(get_info);
	get_info = check_rest(get_info);
	return (dreal);
}
