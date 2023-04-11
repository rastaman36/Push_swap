# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 05:18:14 by mochaoui          #+#    #+#              #
#    Updated: 2023/04/11 05:35:39 by mochaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address -g3

RM = rm -rf

SRCS = main.c parse_data.c lst.c ft_atoi.c instructions.c

$(NAME) :
	make all -C libft
	make all -C pro
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -Lpro -lftprintf -o $(NAME)


all : $(NAME)


fclean : clean
	$(RM) $(NAME)

clean :
	make fclean -C pro
	make fclean -C libft

re : fclean all