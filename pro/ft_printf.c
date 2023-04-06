/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:24:02 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/05 16:13:07 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *r, ...)
{
	va_list	arguments;
	int		a;
	int		counter;

	va_start(arguments, r);
	a = 0;
	counter = 0;
	while (r[a])
	{
		if (r[a] == '%')
		{
			a++;
			ft_printformat(arguments, r[a], &counter);
		}
		else
			ft_putchar(r[a], &counter);
		a++;
	}
	va_end(arguments);
	return (counter);
}
