/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:03:44 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/19 23:03:44 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_rot(t_stack **stack_b, int pos)
{
	if (pos == -1)
		return ;
	if (pos < (size_list(*stack_b) / 2))
		fun_ra(stack_b);
	else
		fun_rra(stack_b);
}

void	b_rotation(t_stack **stack_b, int pos)
{
	if (pos == -1)
		return ;
	if (pos < (size_list(*stack_b) / 2))
		fun_rb(stack_b);
	else
		fun_rrb(stack_b);
}

int	searching_for_index(t_stack **stack_a, int indexx)
{
	t_stack	*ptr;
	int		counter;
	int		position;
	int		flag;

	counter = 0;
	position = 0;
	flag = -1;
	ptr = *stack_a;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index == indexx)
		{
			position = counter;
			flag = 0;
		}
		counter++;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = ptr;
	if (flag == -1)
		return (flag);
	return (position);
}

int	check_biggest_index(t_stack *stack_a)
{
	static int	i;
	int			max;
	t_stack		*ptr;

	ptr = stack_a;
	i = 0;
	max = ptr->index;
	while (ptr != NULL)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}
	free(ptr);
	i++;
	return (max - i +1);
}

void	case100(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk;
	int	counter;

	chunk = 30;
	counter = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index < chunk)
		{
			fun_pb(stack_b, stack_a);
			counter++;
		}
		else if (counter == chunk)
		{
			if (size > 100)
				chunk += 30;
			else
				chunk += 15;
		}
		else
			a_rot(stack_a, searching_for_index(stack_a, (*stack_a)->index));
	}
}
