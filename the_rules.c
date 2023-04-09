/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:44:08 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/09 04:05:30 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack, int content)
{
	s_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->top_of_stack, node);
	stack->size++;
}

void	push_to_b(t_stack *stack, int content)
{
	s_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->top_of_stack, node);
	stack->size++;
}

void	push(t_stack *stack, int content)
{
	s_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_back(&stack->top_of_stack, node);
	stack->size++;
}

int	pop(t_stack *stack)
{
	int		content;
	s_list	*ptr;

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
	dt->stack_a->top_of_stack->content = dt->stack_a->top_of_stack->next->content;
	dt->stack_a->top_of_stack->next->content = swap;
	swap = dt->stack_b->top_of_stack->content;
	dt->stack_b->top_of_stack->content = dt->stack_b->top_of_stack->next->content;
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
	s_list	*ptr;

	if (stack->size <= 1)
		return ;
	ptr = stack->top_of_stack;
	content = pop(stack);
	push(stack, content);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	int		content;
	s_list	*ptr;

	if (stack->size <= 1)
		return ;
	ptr = stack->top_of_stack;
	content = pop(stack);
	push(stack, content);
	write(1, "rb\n", 3);
}

void	rr(t_data *dt)
{
	int		content;
	s_list	*ptr;

	if (dt->stack_a->size <= 1 || dt->stack_b->size <= 1)
		return ;
	ptr = dt->stack_a->top_of_stack;
	content = pop(dt->stack_a);
	push(dt->stack_a, content);
	ptr = dt->stack_b->top_of_stack;
	content = pop(dt->stack_b);
	push(dt->stack_b, content);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *stack)
{
	s_list	*last_node;
	s_list	*blast_node;

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
	s_list	*last_node;
	s_list	*blast_node;

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
	s_list	*last_node;
	s_list	*blast_node;

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