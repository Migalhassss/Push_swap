/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:57:15 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/27 10:17:16 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sorted(t_stack **list)
{
	t_stack	*tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int	order(t_stack **list, int size)
{
	int	i;

	i = 0;
	while ((*list)->index != 0)
	{
		rotate(list);
		i++;
	}
	if (ft_sorted(list) == 1)
	{
		if (i > (size / 2))
		{
			if (size == 5 && i == 3)
				ft_printf("rra\n");
			ft_printf("rra\n");
		}
		else
			while (i-- > 0)
				ft_printf("ra\n");
		return (1);
	}
	else
		while (i-- > 0)
			reverse(list);
	return (0);
}

void	index_reset(t_stack **list)
{
	t_stack	*lst;

	lst = *list;
	while (lst != NULL)
	{
		lst->index = -1;
		lst = lst->next;
	}
	get_index(list);
}

void	rotate_to_first(t_stack **lst, int size)
{
	int	i;

	i = 0;
	while ((*lst)->index != 0)
	{
		rotate(lst);
		i++;
	}
	if ((i > (size / 2)))
	{
		if (size == 5 && i == 3)
			ft_printf("rra\n");
		ft_printf("rra\n");
	}
	else
	{
		while (i > 0)
		{
			ft_printf("ra\n");
			i--;
		}
	}
}
