/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:36:01 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/15 01:06:31 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_data *dt)
{
	int		i;
	s_list	*ptr;

	i = 0;
	ptr = dt->numbers;
	while (ptr)
	{
		if (ptr->content == dt->stack_a->top_of_stack->content)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	index_small_number(t_stack *stack)
{
	int		i;
	s_list	*ptr;

	i = 1;
	ptr = stack->top_of_stack;
	while (ptr)
	{
		if (ptr->content == small_number(stack))
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	index_big_number(t_stack *stack)
{
	int		i;
	s_list	*ptr;

	i = 1;
	ptr = stack->top_of_stack;
	while (ptr)
	{
		if (ptr->content == big_number(stack))
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}


int	big_number(t_stack *stack)
{
	int		biggest_number;
	s_list	*ptr;

	biggest_number = stack->top_of_stack->content;
	ptr = stack->top_of_stack->next;
	while (ptr)
	{
		if (biggest_number < ptr->content)
			biggest_number = ptr->content;
		ptr = ptr->next;
	}
	return (biggest_number);
}

int	small_number(t_stack *stack)
{
	int		smallest_number;
	s_list	*ptr;

	ptr = stack->top_of_stack;
	smallest_number = ptr->content;
	while (ptr->next)
	{
		if (smallest_number > ptr->next->content)
			smallest_number = ptr->next->content;
		ptr = ptr->next;
	}
	return (smallest_number);
}

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