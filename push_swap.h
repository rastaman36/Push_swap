/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:18:47 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/17 03:13:32 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct d_list
{
	int				content;
	struct d_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*top_of_stack;
	int		size;
}	t_stack;

typedef struct s_data
{
	char	**array_arg;
	int		saved_atoi;
	int		range_min;
	int		range_max;
	int		node_index;
	t_list	*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

int		valid_argument(char *str);
int		cmp_integers(char *s1, char *s2);
char	**spliting_arguments(char **str);
void	ft_double_args(t_data *dt);
t_list	*ft_lstnew(int content);
void	ft_error(void);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
void	add_to_stack(t_stack *stack, t_list *l_numbers);
void	sorting(t_list *numbers);
int		check_sorted_list(t_data *dt);
void	sorting_algorithm(t_data *dt);
void	rotate_a(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	swap_a(t_stack *stack);
void	sort3(t_stack *stack);
int		big_number(t_stack *stack);
int		small_number(t_stack *stack);
int		index_big_number(t_stack *stack);
int		index_small_number(t_stack *stack);
int		get_index(t_data *dt);
void	push_a(t_data *dt);
void	push_b(t_data *dt);
void	sort5(t_data *dt);
void	sort_range(t_data *dt);
void	rotate_b(t_stack *stack);
void	the_last_sorting(t_data *dt);
void	reverse_rotate_b(t_stack *stack);
int		pop(t_stack *stack);
void	*ft_calloc(size_t count, size_t size);
void	push(t_stack *stack, int content);
void	push_to_a(t_stack *stack, int content);
void	push_to_b(t_stack *stack, int content);
int		get_index(t_data *dt);
void	bonus_swap_a(t_stack *stack);
void	bonus_rotate_b(t_stack *stack);
void	bonus_rr(t_data *dt);
void	bonus_reverse_rotate_a(t_stack *stack);
void	bonus_reverse_rotate_b(t_stack *stack);
void	bonus_rrr(t_data *dt);
void	bonus_swap_b(t_stack *stack);
void	bonus_ss(t_data *dt);
void	bonus_push_a(t_data *dt);
void	bonus_push_b(t_data *dt);
void	bonus_rotate_a(t_stack *stack);
void	check_args(int argc, char **argv);
void	instruction(t_data *dt, char *str);
int		check_if_sorted(t_data *dt);
char	*get_next_line(int fd);

#endif