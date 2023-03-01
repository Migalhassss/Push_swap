/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:34:32 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 15:39:47 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	breverse(t_stack **stack)
{
	t_stack	*lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = list_last(*stack);
	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = *stack;
	(*stack)->prev = lst;
	*stack = (*stack)->prev;
}

void	bfun_rra(t_stack **list_a)
{
	breverse(list_a);
}

void	bfun_rrb(t_stack **list_b)
{
	breverse(list_b);
}

void	bfun_rrr(t_stack **list_a, t_stack **list_b)
{
	breverse(list_a);
	breverse(list_b);
}
