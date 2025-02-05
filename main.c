/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:18:25 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/17 03:29:53 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*dt;
	int		a;

	a = 1;
	dt = ft_calloc(1, sizeof(t_data));
	if (!dt || ac > 1)
	{
		while (a < ac)
		{
			if (!valid_argument(av[a]))
				ft_error();
			a++;
		}
		dt->array_arg = spliting_arguments(av);
		ft_double_args(dt);
		dt->stack_b = ft_calloc(1, sizeof(t_stack));
		dt->stack_a = ft_calloc(1, sizeof(t_stack));
		if (!dt->stack_a || !dt->stack_b)
			return (0);
		dt->stack_b->top_of_stack = NULL;
		add_to_stack(dt->stack_a, dt->numbers);
		sorting(dt->numbers);
		sorting_algorithm(dt);
	}
	return (0);
}
