/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:55:35 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/26 10:48:54 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap (t_stack **lst)
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

void	fun_sa(t_stack **list_a)
{
	swap(list_a);
	ft_printf("sa\n");
}

void	fun_sb(t_stack **list_b)
{
	swap(list_b);
	ft_printf("sb\n");
}

void	fun_ss(t_stack **list_a, t_stack **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
