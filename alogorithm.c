/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:36:01 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/18 01:31:07 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *stack)
{
	if (stack->top_of_stack->content > stack->top_of_stack->next->content)
	{
		rotate_a(stack);
		exit(0);
	}
	if (stack->top_of_stack->content == big_number(stack))
		rotate_a(stack);
	if (stack->top_of_stack->next->content == big_number(stack))
		reverse_rotate_a(stack);
	if (stack->size > 2)
		if (stack->top_of_stack->next->content == small_number(stack) && \
		stack->top_of_stack->next->next->content == big_number(stack))
			swap_a(stack);
}

void	sort5(t_data *dt)
{
	int	index;

	index = index_small_number(dt->stack_a);
	while (dt->stack_a->size > 3)
	{
		while (dt->stack_a->top_of_stack->content != small_number(dt->stack_a))
		{
			if (index > dt->stack_a->size / 2)
				reverse_rotate_a(dt->stack_a);
			else
				rotate_a(dt->stack_a);
		}
		push_b(dt);
	}
	sort3(dt->stack_a);
	while (dt->stack_b->size > 0)
		push_a(dt);
}

void	sort_range(t_data *dt)
{
	dt->range_min = 0;
	if (dt->stack_a->size >= 90)
		dt->range_max = 15;
	if (dt->stack_a->size >= 150)
		dt->range_max = 35;
	while (dt->stack_a->top_of_stack)
	{
		dt->node_index = get_index(dt);
		if ((dt->node_index >= dt->range_min)
			&& dt->node_index <= dt->range_max)
		{
			push_b(dt);
			dt->range_max++;
			dt->range_min++;
		}
		else if (dt->node_index >= dt->range_max)
			rotate_a(dt->stack_a);
		else if (dt->node_index <= dt->range_min)
		{
			push_b(dt);
			rotate_b(dt->stack_b);
			dt->range_max++;
			dt->range_min++;
		}
	}
}

void	the_last_sorting(t_data *dt)
{
	while (dt->stack_b->size > 0)
	{
		dt->node_index = index_big_number(dt->stack_b);
		while (dt->stack_b->top_of_stack->content != big_number(dt->stack_b))
		{
			if (dt->node_index < (dt->stack_b->size / 2))
				rotate_b(dt->stack_b);
			else
				reverse_rotate_b(dt->stack_b);
		}
		if (dt->stack_b->top_of_stack->content == big_number(dt->stack_b))
			push_a(dt);
	}
}

void	sorting_algorithm(t_data *dt)
{
	if (check_sorted_list(dt))
		exit(0);
	if (dt->stack_a->size <= 3)
		sort3(dt->stack_a);
	else if (dt->stack_a->size > 3 && dt->stack_a->size <= 5)
		sort5(dt);
	else
	{
		sort_range(dt);
		the_last_sorting(dt);
	}
}
