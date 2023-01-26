/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:06 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/26 16:31:38 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  ftcheck(t_stack *list, int ind)
{
	t_stack *tmp;
	int	i;
	
	i = 0;
	tmp = list;
	while (tmp)
	{
		if (list->index == ind)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	min_cust(int index, int size)
{
	int	move1;
	int	move2;
	int	tmp;
	
	move1 = 0;
	move2 = 0;
	tmp = index;
	while (index <= size)
	{
		move1++;
		index++;
	}
	while (tmp >= 0)
	{
		move2++;
		tmp--;
	}
	if (move1 > move2)
		return(0); //rb
	else if (move2 > move1)
		return(1); //rrb
	return (-1);
}

int	check_cust(int index, int size)
{
	int	move1;
	int	move2;
	int	tmp;
	
	move1 = 0;
	move2 = 0;
	tmp = index;
	while (index <= size)
	{
		move1++;
		index++;
	}
	while (tmp >= 0)
	{
		move2++;
		tmp--;
	}
	if (move1 > move2)
		return(move2);
	else if (move2 > move1)
		return(move1);
	return (-1);
}

static int	get_first(t_stack **list, int ind)
{
	t_stack	*lst;
	int		i;
	
	i = 0;
	if (!(*list))
		return (0);
	lst = *list;
	while (ind == -1)
	{
		ind = ftcheck(*list, ind);
		ind++;
	}
	while (lst)
	{
		if (lst->index == ind)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack **list)
{
	t_stack *tmp;
	int i;
	
	i = 0;
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void sort_25(t_stack **list_a, t_stack **list_b)
{
	int	index;
	int	i;
	int	ind;
	int	cust;
	t_stack *tmp;
	
	ft_sorted(list_a);
	i = 0;
	ind = 0;
	while (ft_sorted(list_b) != 1)
	{
		index = get_first(list_b, ind);
		tmp = *list_b;
		while (i < index)
		{
			tmp = tmp->next;
			i++;
		}
		cust = min_cust(index, size_list(*list_b));
		if(check_cust(index, size_list(*list_b)) == 0)
		{
			while (cust < 25)
			{
				fun_rb(list_b);
				cust++;
			}
			
		}
		else if (check_cust(index, size_list(*list_b)) == 1)
		{
			while (cust > 10)
			{
				fun_rrb(list_b);
				cust--;
			}
		}
		ind++;
	}
}

void	sort(t_stack **list_a, t_stack **list_b, int size)
{
	int i;
	if (size == 100)
	{
		while (ft_sorted(list_a) != 1)
		{
			i = 0;
			while (i < 25)
			{
				fun_pb(list_b, list_a);
				i++;
			}
			sort_25(list_b, list_b);
		}
	}
}