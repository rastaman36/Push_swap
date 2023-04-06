/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:07:31 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/04 05:31:37 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copylist;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	copylist = *lst;
	copylist = ft_lstlast(copylist);
	copylist->next = new;
}