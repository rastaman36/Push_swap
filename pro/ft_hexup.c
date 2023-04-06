/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:43:02 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/03 22:06:25 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexup(unsigned int i, int *counter)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (i >= 0 && i < 16)
	{
		ft_putchar(s[i], counter);
	}
	if (i >= 16)
	{
		ft_hexup((i / 16), counter);
		ft_hexup((i % 16), counter);
	}
}
