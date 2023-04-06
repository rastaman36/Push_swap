/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:46:02 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/03 01:21:24 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*counter += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', counter);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
		ft_putchar(n + '0', counter);
}
