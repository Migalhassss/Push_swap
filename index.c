/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:42:12 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/20 11:42:12 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_first(t_stack **list)
{
	t_stack	*lst;
	t_stack	*lst_min;
	int		min;

	if (!(*list))
		return (NULL);
	min = 0;
	lst_min = NULL;
	lst = *list;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || lst->content < lst_min->content))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	get_index(t_stack **list)
{
	t_stack	*lst;
	int		index;

	index = 0;
	lst = get_first(list);
	while (lst != NULL)
	{
		lst->index = index++;
		lst = get_first(list);
	}
}
