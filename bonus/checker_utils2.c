/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:48:50 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 15:48:50 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	bcheck_doubles(t_stack *list)
{
	int		tmp;
	t_stack	*clone;

	while (list != NULL && list->next != NULL)
	{
		tmp = list->content;
		clone = list;
		while (clone->next != NULL)
		{
			clone = clone->next;
			if (clone->content == tmp)
				return (0);
			else if (clone->content > 2147483647
				|| clone->content < -2147483647)
				return (0);
		}
		list = list->next;
	}
	return (1);
}

void	lst_addfront(t_stack **list, t_stack *news)
{
	if (!list || !news)
		return ;
	if (!(*list))
	{
		*list = news;
		(*list)->prev = NULL;
		(*list)->next = NULL;
		return ;
	}
	(*list)->prev = news;
	news->next = *list;
	*list = news;
	news->prev = NULL;
}

t_stack	*list_last(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	size_list(t_stack *list)
{
	int		i;
	t_stack	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
