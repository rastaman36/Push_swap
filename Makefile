# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 05:18:14 by mochaoui          #+#    #+#              #
#    Updated: 2023/04/18 02:04:19 by mochaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = cc

CFLAGS = -Werror -Wall -Wextra #fsanitize=address -g3

RM = rm -rf

SRCS = main.c parse_data.c lst.c ft_atoi.c instructions.c the_rules.c the_rules1.c the_rules2.c alogorithm.c toolsalgorithm.c

SRCSB = the_rules_bonus.c the_rules1_bonus.c the_rules2_bonus.c checker_bonus.c get_next_line.c get_next_line_utils.c \
		parse_data.c lst.c ft_atoi.c instructions.c the_rules.c the_rules1.c the_rules2.c alogorithm.c toolsalgorithm.c \

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)


all : $(NAME)

bonus: $(NAME2)

$(NAME2) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCSB) libft/libft.a -o $(NAME2)

fclean : clean
	$(RM) $(NAME) $(NAME2)

clean :
	make fclean -C libft

re : fclean all