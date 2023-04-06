# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 17:44:27 by mochaoui          #+#    #+#              #
#    Updated: 2023/04/04 05:38:56 by mochaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_strjoin.c ft_split.c ft_strdup.c \
ft_strlcpy.c ft_strlen.c ft_strlcat.c  ft_substr.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c  ft_strcmp.c ft_strncmp.c ft_strrchr.c ft_strtrim.c ft_strchr.c ft_itoa.c add_back.c add_front.c last.c


NAME = libft.a

OBJS	= ${SRCS:.c=.o}

AR = ar rcs

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

.c.o:
	${CC} ${CFLAGS} -c $<
	
all:	${NAME}
 
${NAME}: ${OBJS}
	${AR} ${NAME} $^

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean ${NAME}
