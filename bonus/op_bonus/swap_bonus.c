/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:55:35 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 15:39:54 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	swap(t_stack **lst)
{
	int	index;
	int	content;

	if (!(*lst)->next)
		return ;
	content = (*lst)->next->content;
	index = (*lst)->next->index;
	(*lst)->next->content = (*lst)->content;
	(*lst)->next->index = (*lst)->index;
	(*lst)->content = content;
	(*lst)->index = index;
}

void	bfun_sa(t_stack **list_a)
{
	swap(list_a);
}

void	bfun_sb(t_stack **list_b)
{
	swap(list_b);
}

void	bfun_ss(t_stack **list_a, t_stack **list_b)
{
	swap(list_a);
	swap(list_b);
}
