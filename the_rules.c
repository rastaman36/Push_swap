/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:44:08 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/16 01:35:19 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->top_of_stack, node);
	stack->size++;
}

void	push_to_b(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->top_of_stack, node);
	stack->size++;
}

void	push(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_back(&stack->top_of_stack, node);
	stack->size++;
}

int	pop(t_stack *stack)
{
	int		content;
	t_list	*ptr;

	content = stack->top_of_stack->content;
	ptr = stack->top_of_stack;
	if (stack->size >= 1)
	{
		stack->top_of_stack = stack->top_of_stack->next;
		stack->size--;
	}
	free(ptr);
	return (content);
}

void	swap_a(t_stack *stack)
{
	int	swap;

	if (stack->size <= 1)
		return ;
	swap = stack->top_of_stack->content;
	stack->top_of_stack->content = stack->top_of_stack->next->content;
	stack->top_of_stack->next->content = swap;
	write(1, "sa\n", 3);
}
