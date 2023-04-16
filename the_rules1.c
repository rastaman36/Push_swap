/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:57:27 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/16 01:35:00 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *stack)
{
	int		content;

	if (stack->size <= 1)
		return ;
	content = pop(stack);
	push(stack, content);
	write(1, "rb\n", 3);
}

void	rr(t_data *dt)
{
	int		content;

	if (dt->stack_a->size <= 1 || dt->stack_b->size <= 1)
		return ;
	content = pop(dt->stack_a);
	push(dt->stack_a, content);
	content = pop(dt->stack_b);
	push(dt->stack_b, content);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *stack)
{
	t_list	*last_node;
	t_list	*blast_node;

	blast_node = stack->top_of_stack;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&stack->top_of_stack, last_node);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	t_list	*last_node;
	t_list	*blast_node;

	blast_node = stack->top_of_stack;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&stack->top_of_stack, last_node);
	write(1, "rrb\n", 4);
}

void	rrr(t_data *dt)
{
	t_list	*last_node;
	t_list	*blast_node;

	if (dt->stack_a->size <= 1 || dt->stack_b->size <= 1)
		return ;
	blast_node = dt->stack_a->top_of_stack;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&dt->stack_a->top_of_stack, last_node);
	blast_node = dt->stack_b->top_of_stack;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&dt->stack_b->top_of_stack, last_node);
	write(1, "rrr\n", 4);
}
