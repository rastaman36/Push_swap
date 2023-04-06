# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 22:57:00 by mochaoui          #+#    #+#              #
#    Updated: 2022/11/02 01:39:32 by mochaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printformat.c ft_unsigned_int.c ft_printadress.c ft_hexup.c ft_hexlu.c

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

CC = gcc

.c.o :
	${CC} ${CFLAGS} -c $<

all : ${NAME}

${NAME} : ${OBJS}
		${AR} ${NAME} $^

clean :
	rm -f ${OBJS}

fclean :	clean
	rm -f ${NAME}

re :	fclean ${NAME}
