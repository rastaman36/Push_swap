/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:18:47 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/06 02:47:46 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "libft/libft.h"
# include "pro/ft_printf.h"

typedef struct s_data
{
	char 	**array_arg;
}	t_data;

typedef struct d_list
{
	void			*content;
	struct s_list	*next;
}	d_list;