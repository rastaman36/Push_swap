/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:24:44 by mochaoui          #+#    #+#             */
/*   Updated: 2022/11/03 02:50:49 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *r, ...);
void	ft_putchar(int c, int *counter);
void	ft_unsigned_int(unsigned int n, int *counter);
void	ft_hexup(unsigned int i, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_hexlu(unsigned int i, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_printformat(va_list arg, const char form, int *counter);
void	ft_printadress(unsigned long i, int *counter);

#endif