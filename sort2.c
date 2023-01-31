/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:52:51 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/31 17:00:37 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_cust(int index, int size)
{
	int	move1;
	int	move2;
	int	tmp;
	
	move1 = 0;
	move2 = 0;
	tmp = index;
	while (index < size)
	{
		move1++;
		index++;
	}
	while (tmp > 0)
	{
		move2++;
		tmp--;
	}
	if (move1 < move2 || move2 == move1)
		return(0);
	else if (move2 < move1 || move2 == move1)
		return(1);
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
	while (index < size)
	{
		move1++;
		index++;
	}
	while (tmp > 0)
	{
		move2++;
		tmp--;
	}
	if (move1 < move2 || move2 == move1)
		return(move1);
	else if (move2 < move1 || move2 == move1)
		return(move2);
	return (-1);
}

void	ft_check_index_aux(t_stack **list_a, int where)
{
	int	cust;
	cust = 0;
	if (list_a)
	{
		cust = min_cust(where, size_list(*list_a));
		if (cust == 0)
			return ;
		if(check_cust(where, size_list(*list_a)) == 0)
		{
			while (cust > 0)
			{
				fun_rra(list_a);
				cust--;
			}
		}
		else if (check_cust(where, size_list(*list_a)) == 1)
		{
			while (cust > 0)
			{
				fun_ra(list_a);
				cust--;
			}	
		}
	}
}

void	ft_check_index(t_stack **list_a, t_stack **list_b, int end)
{
	t_stack		*lst;
	int			where;
	
	lst = *list_a;
	where = 0;
	end -= 1;
	while (lst)
	{
		if (lst->index <= end)
		{
			ft_check_index_aux(list_a, where);
			fun_pb(list_b, list_a);
			lst = *list_a;
			where = 0;
		}
		else
		{
			lst = lst->next;
			where++;
		}
	}
}

void	pb_spam(t_stack **list_a, t_stack **list_b)
{
	int size;
	
	if (!(list_a))
		return ;
	size = size_list(*list_a);
	while (size > 0)
	{
		fun_pb(list_b, list_a);
		size--;
	}
	return ; 
}

int	get_max_index(t_stack **list)
{
	int	index;
	t_stack *tmp;

	tmp = *list;
	index = 0;
	while (tmp)
	{
		if (tmp->index > index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

void	sort_chunks_aux(t_stack **list_b, int where)
{
	int cust;
	
	cust = 0;
	if (list_b)
	{
		cust = min_cust(where, size_list(*list_b));
		if (cust == 0)
			return;
		if (check_cust(where, size_list(*list_b)) == 0)
		{
			while (cust > 0)
			{
				fun_rrb(list_b);
				cust--;
			}
		}
		else if (check_cust(where, size_list(*list_b)) == 1)
		{
			while (cust > 0)
			{
				fun_rb(list_b);
				cust--;
			}
		}
	}
}

void	sort_chunks(t_stack **list_a, t_stack **list_b)
{
	int	where;
	int index;
	t_stack	*list;

	list = *list_b;
	where = 0;
	index = get_max_index(list_b);
	while (list)
	{
		if (index == list->index)
		{
			sort_chunks_aux(list_b, where);
			fun_pa(list_a, list_b);
			list = *list_b;
			where = 0;
			index--;
		}
		else
		{
			list = list->next;
			where++;
		}
	}
}

void	sort2(t_stack **list_a, t_stack **list_b, int size)
{
	int	chunk;
	int res;
	int res2;
	int restmp;
	chunk = 1;

	size = size_list(*list_a);
	res	= size / 4;
	res2 = size % 4;
	if (res2 != 0 )
		res += res2;
	restmp = res;
	while (ft_sorted(list_a) != 1 && chunk < 8)
	{
		if (chunk < 5)
			ft_check_index(list_a, list_b, res);
		else if (chunk == 6)
			pb_spam(list_a, list_b);
		else if (chunk == 7)
			sort_chunks(list_a, list_b);
		res += restmp;
		chunk++;
	}
}
