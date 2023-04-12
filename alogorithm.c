/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:36:01 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/12 00:16:34 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigest(t_stack *stack)
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

int	smallest(t_stack *stack)
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
	if (stack->top_of_stack->content == bigest(stack))
		rotate_a(stack);
	if (stack->top_of_stack->next->content == bigest(stack))
		reverse_rotate_a(stack);
	if (stack->size > 2)
		if (stack->top_of_stack->next->content == smallest(stack) && \
		stack->top_of_stack->next->next->content == bigest(stack))
			swap_a(stack);
}

void	sorting_algorithm(t_data *dt)
{
	if (check_sorted_list(dt))
		exit(0);
    if (dt->stack_a->size <= 3)
        sort3(dt->stack_a);
		
        
}