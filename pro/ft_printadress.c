/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:07:52 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/03 01:31:25 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(unsigned long i, int *counter)
{
	char	*s;

	s = "0123456789abcdef";
	if (i >= 0 && i < 16)
	{
		ft_putchar(s[i], counter);
	}
	else
	{
		ft_print((i / 16), counter);
		ft_print((i % 16), counter);
	}
}

void	ft_printadress(unsigned long i, int *counter)
{
	write(1, "0x", 2);
	*counter += 2;
	ft_print(i, counter);
}
