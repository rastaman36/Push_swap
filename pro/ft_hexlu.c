/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:43:21 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/03 02:48:07 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexlu(unsigned int i, int *counter)
{
	char	*s;

	s = "0123456789abcdef";
	if (i >= 0 && i < 16)
	{
		ft_putchar(s[i], counter);
	}
	if (i >= 16)
	{
		ft_hexlu((i / 16), counter);
		ft_hexlu((i % 16), counter);
	}
}
