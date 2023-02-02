/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:52:51 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/02 16:49:42 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tree_sort2(t_stack **list_a)
{
	while (ft_sorted(list_a) != 1)
	{
		if (((*list_a)->index > (*list_a)->next->index) 
			&& ((*list_a)->index < (*list_a)->next->next->index))
			fun_sa(list_a);
		else if (((*list_a)->index > ((*list_a)->next->index)) 
			&& ((*list_a)->index > (*list_a)->next->next->index))
			fun_ra(list_a);
		else
			fun_rra(list_a);
	}
}

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

int	cust_min(t_stack **a_list, int index, int size)
{
	int	move1;
	int	move2;
	int	tmp;
	t_stack *lst;

	(void) lst;
	(void) a_list;
	move1 = 0;
	move2 = 0;
	tmp = size + 1;
	while (index < size)
	{
		move1++;
		index++;
	}
	while (tmp > index)
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

void	ft_check_index(t_stack **list_a, t_stack **list_b, int end, int size)
{
	t_stack		*lst;
	int			where;
	int			hold;
	
	lst = *list_a;
	hold = size - 4;
	where = 0;
	end -= 1;
	while (lst)
	{
		if (lst->index <= end && lst->index <= hold)
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

void	send_3(t_stack **list_a, t_stack **list_b)
{
	fun_rrb(list_b);
	fun_pa(list_a, list_b);
	fun_pa(list_a, list_b);
	fun_pa(list_a, list_b);
}



int	check_where(t_stack **a_list, int index)
{
	t_stack	*lst;	
	int	where;

	lst = *a_list;
	where = 0;
	while (lst)
	{
		if (lst->index < index)
			where = lst->index;
		lst = lst->next;
	}
	return (where);
}

int	min_cust_2(t_stack **a_list, int index, int cust, int check)
{
	t_stack *lst;
	int where;
	int	cust_a;

	(void) index;
	lst = *a_list;
	if (lst)
	{
		where = check_where(a_list, lst->index);
		cust_a = cust_min(a_list, where, size_list(*a_list));
		if (cust_a < cust || check == 0)
		{
			check = 1;
			cust = cust_a;
		}
		lst = lst->next;
	}
	return (cust);
}

int	check_chakalaka(t_stack **list_a, t_stack **list_b)
{
	t_stack	*a_lst;
	t_stack	*b_lst;
	int		where;
	int		b_index;
	int		a_index;
	int		final_cust;
	int		hold;
	
	where = 0;
	final_cust = -1;
	a_lst = *list_a;
	b_lst = *list_b;
	while (b_lst != NULL && a_lst != NULL)
	{
		b_index = min_cust(b_lst->index, size_list(*list_b));
		a_index = min_cust_2(list_a, b_lst->index, a_index, where);
		if ((b_index + a_index) < final_cust || final_cust == -1)
		{
			final_cust = b_index + a_index;
			hold = b_lst->index;
		}
		b_lst = b_lst->next;
		where++;
	}
	return (hold);
}

void	sort_chunks_aux_a(t_stack **list, int index)
{
	int	cust;
	int	where;
	
	if(list)
	{
		where = check_where(list, index);
		cust = min_cust(where, size_list(*list));
		if (cust == 0)
			return;
		if (check_cust(where, size_list(*list)) == 1)
		{
			while (cust > 0)
			{
				fun_rra(list);
				cust--;
			}
		}
		else if (check_cust(where, size_list(*list)) == 0)
		{
			while (cust > 0)
			{
				fun_ra(list);
				cust--;
			}
		}
	}
}

void	sort_chunks(t_stack **list_a, t_stack **list_b)
{
	t_stack	*lst;
	int		where;
	int		index;

	lst = *list_b;
	where = 0;
	index = check_chakalaka(list_a, list_b);
	while (lst)
	{
		if	(lst->index == index)
		{
			sort_chunks_aux(list_b, where);
			fun_pa(list_a, list_b);
			sort_chunks_aux_a(list_a, index);
			index = check_chakalaka(list_a, list_b);
			lst = *list_b;
			where = 0;
		}
		else
		{
			lst = lst->next;
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
	while (chunk < 8)
	{
		if (chunk < 5)
			ft_check_index(list_a, list_b, res, size);
		else if (chunk == 6)
			tree_sort2(list_a);
		else if (chunk == 7)
			sort_chunks(list_a, list_b);
		res += restmp;
		chunk++;
	}
}


// int	check_chakalaka(t_stack **list_a, t_stack **list_b)
// {
// 	t_stack *tmp;
// 	int	where;
// 	int	cust;
// 	int custmp;
// 	int index;
// 	int	who;
// 	tmp = *list_b;
// 	cust = -1;
// 	where = 0;
// 	while (tmp)
// 	{
// 		if ((*list_a)->index < tmp->index)
// 		{
// 			custmp = min_cust(where, size_list(*list_b));
// 			if (custmp < cust || cust == -1)
// 			{
// 				cust = min_cust(where, size_list(*list_b));
// 				index = tmp->index;
// 			}
// 		}
// 		tmp = tmp->next;
// 		where++;
// 	}
// 	return (index);

// }

// int	get_next_index(t_stack **list_a)
// {
// 	t_stack *tmp;
// 	int	index;
	
// 	index = list_last(*list_a);
// 	tmp = *list_a;
// 	while (tmp)
// 	{
// 		if (tmp->index > index)
// 			index = tmp->index;
// 		tmp = tmp->next;
// 	}
// 	return (index);
// }
// void	sort_a(t_stack **list_a)
// {
// 	int	where;
// 	int index;
// 	t_stack	*list;

// 	list = *list_a;
// 	where = 0;
// 	index = get_next_index(list_a);
// 	while (list)
// 	{
// 		if (index == list->index)
// 		{
// 			ft_check_index_aux(list_a, where);
// 			index = get_next_index(list_a);
// 			list = *list_a;
// 			where = 0;
// 		}
// 		else
// 		{
// 			list = list->next;
// 			where++;
// 		}
// 	}
// }

// void	sort_chunks2(t_stack **list_a, t_stack **list_b)
// {
// 	int	where;
// 	int index;
// 	t_stack	*list;

// 	list = *list_b;
// 	where = 0;
// 	send_3(list_a, list_b);
// 	index = check_chakalaka(list_a, list_a);
// 	while (list)
// 	{
// 		if (index == list->index)
// 		{
			
// 			sort_chunks_aux(list_b, where);
// 			fun_pa(list_a, list_b);
// 			sort_a(list_a);
// 			list = *list_b;
// 			where = 0;
// 			index = check_chakalaka(list_a, list_b);
// 		}
// 		else
// 		{
// 			list = list->next;
// 			where++;
// 		}
// 	}
// }