/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:40:36 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/18 05:42:48 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_data *dt)
{
	t_list	*stack;
	t_list	*stack_sorted;

	stack = dt->stack_a->top_of_stack;
	stack_sorted = dt->numbers;
	while (stack && stack_sorted)
	{
		if (stack->content == stack_sorted->content
			&& dt->stack_b->size == 0)
		{
			stack = stack->next;
			stack_sorted = stack_sorted->next;
		}
		else
		{
			write(1, "KO\n", 3);
			exit(0);
		}
	}
	return (1);
}

void	instruction(t_data *dt, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		bonus_swap_a(dt->stack_a);
	else if (ft_strcmp(str, "sb\n"))
		bonus_swap_b(dt->stack_b);
	else if (ft_strcmp(str, "ss\n"))
		bonus_ss(dt);
	else if (ft_strcmp(str, "pa\n"))
		bonus_push_a(dt);
	else if (ft_strcmp(str, "pb\n"))
		bonus_push_b(dt);
	else if (ft_strcmp(str, "ra\n"))
		bonus_rotate_a(dt->stack_a);
	else if (ft_strcmp(str, "rb\n"))
		bonus_rotate_b(dt->stack_b);
	else if (ft_strcmp(str, "rr\n"))
		bonus_rr(dt);
	else if (ft_strcmp(str, "rra\n"))
		bonus_reverse_rotate_a(dt->stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		bonus_reverse_rotate_b(dt->stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		bonus_rrr(dt);
	else
		ft_error();
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!valid_argument(av[i]))
			ft_error();
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*array;
	t_data	*dt;

	dt = ft_calloc(1, sizeof(t_data));
	if (!dt || ac > 1)
	{
		dt->array_arg = spliting_arguments(av);
		ft_double_args(dt);
		dt->stack_b = malloc(sizeof(t_stack));
		dt->stack_a = malloc(sizeof(t_stack));
		if (!dt->stack_a || !dt->stack_b)
			return (0);
		add_to_stack(dt->stack_a, dt->numbers);
		sorting(dt->numbers);
		array = get_next_line(0);
		while (array)
		{
			instruction(dt, array);
			free(array);
			array = get_next_line(0);
		}
		if (check_if_sorted(dt))
			write(1, "OK\n", 3);
	}
	return (0);
}
