/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:06 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/23 13:19:13 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **list)
{
	t_stack *tmp;
	int i;
	
	i = 0;
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sort(t_stack **list_a, t_stack **list_b, int size)
{
	int	h;
	int	i;
	int	s;
	if (ft_sorted(&list_a) == 1)
		return ;
	h = size / 2;
	i = 0;
	
	while (i > h)
	{
		(*list_b)->content = (*list_a)->content;
		*list_a = (*list_a)->next;
		*list_b = (*list_b)->next;
		i++;
	}
	i = 0;
	s = is_sorted(&list_b);
	if (s != 0)
	{
		while (i > s)
		{
			fun_pa(list_a, list_b);
			i++;
		}
	}
}