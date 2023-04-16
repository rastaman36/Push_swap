/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:00:29 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/16 01:20:44 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *stack)
{
	int	swap;

	if (stack->size <= 1)
		return ;
	swap = stack->top_of_stack->content;
	stack->top_of_stack->content = stack->top_of_stack->next->content;
	stack->top_of_stack->next->content = swap;
	write(1, "sb\n", 3);
}

void	ss(t_data *dt)
{
	int	swap;

	if (dt->stack_a->size <= 1)
		return ;
	swap = dt->stack_a->top_of_stack->content;
	dt->stack_a->top_of_stack->content = \
	dt->stack_a->top_of_stack->next->content;
	dt->stack_a->top_of_stack->next->content = swap;
	swap = dt->stack_b->top_of_stack->content;
	dt->stack_b->top_of_stack->content = \
	dt->stack_b->top_of_stack->next->content;
	dt->stack_b->top_of_stack->next->content = swap;
	write(1, "ss\n", 3);
}

void	push_a(t_data *dt)
{
	if (dt->stack_b->size == 0)
		return ;
	push_to_a(dt->stack_a, pop(dt->stack_b));
	write(1, "pa\n", 3);
}

void	push_b(t_data *dt)
{
	if (dt->stack_a->size == 0)
		return ;
	push_to_b(dt->stack_b, pop(dt->stack_a));
	write(1, "pb\n", 3);
}

void	rotate_a(t_stack *stack)
{
	int		content;

	if (stack->size <= 1)
		return ;
	content = pop(stack);
	push(stack, content);
	write(1, "ra\n", 3);
}
