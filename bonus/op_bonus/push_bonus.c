/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:27:03 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 15:24:24 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	push(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	if (!list_b || !(*list_b))
		return ;
	tmp = (*list_b)->next;
	lst_addfront(list_a, *list_b);
	*list_b = tmp;
	if (*list_b)
		(*list_b)->prev = NULL;
}

void	bfun_pa(t_stack **list_a, t_stack **list_b)
{
	push(list_a, list_b);
}

void	bfun_pb(t_stack **list_b, t_stack **list_a)
{
	push(list_b, list_a);
}
