/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:34:32 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/26 13:30:41 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack *lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = list_last(*stack);
	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = *stack;
	(*stack)->prev = lst;
	*stack = (*stack)->prev;
}

void	fun_rra(t_stack **list_a)
{
	reverse(list_a);
	ft_printf("rra\n");
}

void	fun_rrb(t_stack **list_b)
{
	reverse(list_b);
	ft_printf("rrb\n");
}

void	fun_rrr(t_stack **list_a, t_stack **list_b)
{
	reverse(list_a);
	reverse(list_b);
	ft_printf("rrr\n");
}
