/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:25:09 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/08 05:42:35 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_lstadd_back(s_list **lst, s_list *new)
{
	s_list	*d;

	if (!lst || !new)
		return ;
	d = *lst;
	if (*lst)
	{
		while (d -> next)
			d = d -> next;
		d -> next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(s_list **lst, s_list *new)
{
	if (new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

s_list	*ft_lstnew(int content)
{
	s_list	*file;

	file = (s_list *)malloc(sizeof(s_list));
	if (!file)
		return (NULL);
	file->content = content;
	file -> next = NULL;
	return (file);
}

int	ft_lstsize(s_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}