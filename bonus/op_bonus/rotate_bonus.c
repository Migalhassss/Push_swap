/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:22:15 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 15:39:31 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	brotate(t_stack **list)
{
	t_stack	*lst;

	if (!(*list) | !(*list)->next)
		return ;
	lst = list_last(*list);
	lst->next = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	lst->next->prev = lst;
	lst->next->next = NULL;
}

void	bfun_ra(t_stack **list_a)
{
	brotate(list_a);
}

void	bfun_rb(t_stack **list_b)
{
	brotate(list_b);
}

void	bfun_rr(t_stack **list_a, t_stack **list_b)
{
	brotate(list_a);
	brotate(list_b);
}
