/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:15:16 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/27 10:15:30 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	index;

	max = check_biggest_index(*stack_b);
	index = searching_for_index(stack_b, max);
	while ((*stack_b) != NULL && index == searching_for_index(stack_b, max))
		index = util(stack_a, stack_b, &max, index);
	if ((*stack_b) == NULL && (*stack_a)->content > (*stack_a)->next->content)
		fun_sa(stack_a);
}

int	util(t_stack **stack_a, t_stack **stack_b, int *max, int index)
{
	if ((*stack_a) && (*stack_a)->next
		&& (*stack_a)->content > (*stack_a)->next->content)
	{
		fun_sa(stack_a);
		(*max)--;
		index = searching_for_index(stack_b, *max);
	}
	else if ((searching_for_index(stack_b, ((*max) - 1)) == 0))
	{
		fun_pa(stack_a, stack_b);
		index = searching_for_index(stack_b, (*max));
	}
	else if (index == 2 && (searching_for_index(stack_b, ((*max) - 1)) == 0))
	{
		fun_pa(stack_a, stack_b);
		(*max)--;
		fun_ra(stack_b);
		fun_pa(stack_a, stack_b);
		(*max)--;
		fun_sa(stack_a);
		index = searching_for_index(stack_b, *max);
	}
	index = util1(stack_a, stack_b, max, index);
	return (index);
}

int	util1(t_stack **stack_a, t_stack **stack_b, int *max, int index)
{
	if (index == 1 && (searching_for_index(stack_b, ((*max) - 1)) == 0))
	{
		fun_sb(stack_b);
		index = searching_for_index(stack_b, (*max));
	}
	else if (searching_for_index(stack_b, (*max)) == 0)
	{
		fun_pa(stack_a, stack_b);
		(*max)--;
		index = searching_for_index(stack_b, (*max));
	}
	else
	{
		b_rotation(stack_b, index);
		index = searching_for_index(stack_b, (*max));
	}
	return (index);
}
