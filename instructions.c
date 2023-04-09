/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:50:20 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/09 00:51:48 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_stack *stack, s_list *l_numbers)
{
	s_list	*ptr;

	ptr = l_numbers;
	while (ptr)
	{
		ft_lstadd_back(&(stack->top_of_stack), ft_lstnew(ptr->content));
		ptr = ptr->next;
	}
	stack->size = ft_lstsize(stack->top_of_stack);
}

void	sorting(s_list *numbers)
{
	int		swap;
	s_list	*ptr_sorted;

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

int	check_ber(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!file)
		return (0);
	if (ft_strncmp(ext, ".ber", 5))
	{
		write(2, ".ber error", 11);
		exit (1);
	}
	return (1);
}