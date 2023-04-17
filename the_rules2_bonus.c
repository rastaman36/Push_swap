/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:27:57 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/17 03:30:05 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_swap_b(t_stack *stack)
{
	int	swap;

	if (stack->size <= 1)
		return ;
	swap = stack->top_of_stack->content;
	stack->top_of_stack->content = stack->top_of_stack->next->content;
	stack->top_of_stack->next->content = swap;
}

void	bonus_ss(t_data *dt)
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
}

void	bonus_push_a(t_data *dt)
{
	if (dt->stack_b->size == 0)
		return ;
	push_to_a(dt->stack_a, pop(dt->stack_b));
}

void	bonus_push_b(t_data *dt)
{
	if (dt->stack_a->size == 0)
		return ;
	push_to_b(dt->stack_b, pop(dt->stack_a));
}

void	bonus_rotate_a(t_stack *stack)
{
	int		content;

	if (stack->size <= 1)
		return ;
	content = pop(stack);
	push(stack, content);
}
