/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:27:07 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/18 06:25:08 by mochaoui         ###   ########.fr       */
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

void	cmp_inst(t_data *dt)
{
	while (dt->array)
	{
		instruction(dt, dt->array);
		free(dt->array);
		dt->array = get_next_line(0);
	}
}
