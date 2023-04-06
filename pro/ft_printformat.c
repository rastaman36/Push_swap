/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:59:09 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/03 03:08:49 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printformat(va_list arg, char form, int *counter)
{
	if (form == '%')
	{
		write(1, "%", 1);
		*counter += 1;
	}
	else if (form == 'c')
		ft_putchar(va_arg(arg, int), counter);
	else if (form == 's')
		ft_putstr(va_arg(arg, char *), counter);
	else if (form == 'u')
		ft_unsigned_int(va_arg(arg, int), counter);
	else if (form == 'p')
		ft_printadress(va_arg(arg, unsigned long), counter);
	else if (form == 'x')
		ft_hexlu(va_arg(arg, unsigned int), counter);
	else if (form == 'X')
		ft_hexup(va_arg(arg, unsigned int), counter);
	else if (form == 'd' || form == 'i')
		ft_putnbr(va_arg(arg, int), counter);
}
