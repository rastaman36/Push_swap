/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 03:06:30 by mochaoui          #+#    #+#             */
/*   Updated: 2023/04/11 05:26:24 by mochaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_args(t_data *dt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	dt->numbers = NULL;
	while (dt->array_arg[i])
	{
		j = i + 1;
		while (dt->array_arg[j])
		{
			if (cmp_integers(dt->array_arg[i], dt->array_arg[j]) == 1)
				ft_error();
			j++;
		}
		i++;
	}
	i = 0;
	while (dt->array_arg[i])
	{
		dt->saved_atoi = ft_atoi(dt->array_arg[i]);
		ft_lstadd_back(&dt->numbers, ft_lstnew(dt->saved_atoi));
		i++;
	}
}

char	**spliting_arguments(char **str)
{
	int		i;
	char	*string;
	char	**tab;

	i = 1;
	string = (char *)malloc(sizeof(char) * 2);
	if (!string)
		return (0);
	string[1] = '\0';
	while (str[i])
	{
		string = ft_strjoin(string, str[i]);
		string = ft_strjoin(string, " ");
		i++;
	}
	tab = ft_split(string, ' ');
	free(string);
	return (tab);
}

int	cmp_integers(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		return (1);
	return (0);
}

int	valid_argument(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] != ' ' && str[i] != '+' && str[i] != '-') && (str[i] < '0'
				|| str[i] > '9'))
			ft_error();
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] < '0'
				|| str[i + 1] > '9'))
			ft_error();
		i++;
		if ((str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i] == '+'
				|| str[i] == '-'))
			ft_error();
	}
	return (1);
}