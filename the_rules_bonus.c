/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:27:07 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/17 03:30:40 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_swap_a(t_stack *stack)
{
	int	swap;

	if (stack->size <= 1)
		return ;
	swap = stack->top_of_stack->content;
	stack->top_of_stack->content = stack->top_of_stack->next->content;
	stack->top_of_stack->next->content = swap;
}
