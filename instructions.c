/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:50:20 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/16 01:36:07 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_stack *stack, t_list *l_numbers)
{
	t_list	*ptr;

	ptr = l_numbers;
	while (ptr)
	{
		ft_lstadd_back(&(stack->top_of_stack), ft_lstnew(ptr->content));
		ptr = ptr->next;
	}
	stack->size = ft_lstsize(stack->top_of_stack);
}

void	sorting(t_list *numbers)
{
	int		swap;
	t_list	*ptr_sorted;

	ptr_sorted = numbers;
	while (numbers && numbers->next)
	{
		if (numbers->content > numbers->next->content)
		{
			swap = numbers->content;
			numbers->content = numbers->next->content;
			numbers->next->content = swap;
			numbers = ptr_sorted;
		}
		else if (numbers->content <= numbers->next->content)
			numbers = numbers->next;
	}
}

int	check_sorted_list(t_data *dt)
{
	t_list	*ptr;

	ptr = dt->stack_a->top_of_stack;
	while (ptr && ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
