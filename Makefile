# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 05:18:14 by mochaoui          #+#    #+#              #
#    Updated: 2023/04/04 05:27:42 by mochaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address -g3

RM = rm -rf

SRCS = main.c

$(NAME) :
	make all -C libft
	make all -C pro
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -lmlx -Lpro -lftprintf -o $(NAME)


all : $(NAME)


fclean : clean
	$(RM) $(NAME)

clean :
	make clean -C pro
	make clean -C libft

re : fclean all