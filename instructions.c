/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:50:20 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/08 07:22:19 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_stack *stack, s_list *l_numbers, t_data *dt)
{
	s_list	*ptr;

	ptr = l_numbers;
	while (ptr)
	{
		ft_lstadd_back(&(stack->top_of_stack), ft_lstnew(ptr->content));
		ptr = ptr->next;
	}
	stack->size = ft_lstsize(stack->top_of_stack);
    printf("%d", dt->stack_a->size);
}