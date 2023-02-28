/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:45:51 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/24 23:45:51 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxchr(t_stack **a)
{
	int		i;
	t_stack	*p;

	i = 0;
	p = *a;
	i = p->index;
	while (p != NULL)
	{
		if (i < p->index)
			i = p->index;
		p = p->next;
	}
	return (i);
}

int	eq_src(t_stack **a, int med, int i)
{
	int		z;
	int		*num;

	num = malloc(sizeof(int) * (i + 1));
	if (!num)
		return (0);
	*num = do_arr2(*a, num);
	z = i;
	while (num[i] != med)
		i--;
	z = z - i;
	i = 0;
	while (num[i] != med)
		i++;
	free(num);
	if (z < i)
		return (1);
	return (0);
}

void	do_sort_pa(t_stack **a, t_stack **b)
{
	while ((*b) != NULL)
	{
		if (!b)
			break ;
		if ((*b)->index != maxchr(b) && !eq_src(b, maxchr(b), size_list(*b)))
			fun_rb(b);
		else if ((*b)->index != maxchr(b)
			&& eq_src(b, maxchr(b), size_list(*b)))
			fun_rrb(b);
		else if ((*b)->index == maxchr(b))
			fun_pa(a, b);
	}
}

void	case500(t_stack **a, t_stack **b)
{
	int	l;

	l = 0;
	while ((*a) != NULL)
	{
		if (l > 1 && (*a)->index <= l)
		{
			fun_pb(b, a);
			l++;
			fun_rb(b);
		}
		else if ((*a)->index <= l + 30)
		{
			fun_pb(b, a);
			l++;
		}
		else if ((*a)->index >= l)
			fun_ra(a);
	}
	do_sort_pa(a, b);
}
