/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:18:47 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/11 03:01:55 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "pro/ft_printf.h"

typedef struct d_list
{
	int			content;
	struct d_list	*next;
}	s_list;

typedef struct s_stack
{
	s_list	*top_of_stack;
	int		size;
}	t_stack;

typedef struct s_data
{
	char 	**array_arg;
	int		saved_atoi;
	s_list	*numbers;
	t_stack	*stack_a;
	t_stack *stack_b;
}	t_data;




int		valid_argument(char *str);
int		cmp_integers(char *s1, char *s2);
char	**spliting_arguments(char **str);
void	ft_double_args(t_data *dt);
s_list	*ft_lstnew(int content);
void	ft_error(void);
void	ft_lstadd_back(s_list **lst, s_list *new);
void	ft_lstadd_front(s_list **lst, s_list *new);
int		ft_lstsize(s_list *lst);
int		ft_atoi(const char *str);
void	add_to_stack(t_stack *stack, s_list *l_numbers);
void	sorting(s_list *numbers);
int		check_sorted_list(t_data *dt);