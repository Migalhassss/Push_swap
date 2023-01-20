/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:22:15 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/20 15:22:52 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*lst;

	if (!(*stack) | !(*stack)->next)
		return ;
	lst = list_last(*stack);
	lst->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lst->next->prev = lst;
	lst->next->prev = NULL;
}

void	fun_ra(t_stack **list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
}

void	fun_rb(t_stack **list_b)
{
	rotate(list_b);
	ft_printf("rb\n");
}

void	fun_rr(t_stack **list_a, t_stack **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}