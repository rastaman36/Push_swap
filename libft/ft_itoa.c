/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:12:44 by mochaoui          #+#    #+#             */
/*   Updated: 2023/03/30 17:35:09 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_lenof_number(int n)
{
	int	length;

	if (n <= 0)
		length = 2;
	else
		length = 1;
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	tmp;
	size_t	r;

	tmp = n;
	r = check_lenof_number(n);
	str = (char *)malloc(sizeof(char) * r);
	if (!str)
		return (NULL);
	str[--r] = '\0';
	if (tmp < 0)
		str[0] = '-';
	else
		str[0] = '0';
	while (tmp)
	{
		if (tmp < 0)
			str[--r] = -tmp % 10 + '0';
		else
			str[--r] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (str);
}
