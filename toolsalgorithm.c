/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolsalgorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:05:40 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/16 01:34:39 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_data *dt)
{
	int		i;
	t_list	*ptr;

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
	t_list	*ptr;

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
	t_list	*ptr;

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
	t_list	*ptr;

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
	t_list	*ptr;

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
