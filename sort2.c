/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:52:51 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/30 18:54:52 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  ft_check_moves(t_stack *list, int ind_2)
{
	t_stack *tmp;
	int	i;
	
	i = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->index == ind_2)
			return (i);
		tmp = tmp->next;
		i++;
	}
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
		ft_printf("----->>> MOVE 1 | %d | MOVE 2 | %d |\n", move1, move2);
	if (move1 < move2 || move2 == move1)
		return(move1);
	else if (move2 < move1 || move2 == move1)
		return(move2);
	return (-1);
}

// static int	get_next_index(t_stack **list, int index)
// {
// 	t_stack	*lst;
// 	int		i;
// 	int		size;
// 	int		res;

// 	i = 0;
// 	if (!(*list))
// 		return (0);
// 	size = size_list(*list);
// 	lst = *list;
// 	while (index > size)
// 	{
// 		res = ft_check_moves(*list, index);
// 		index++;
// 	}
// 	while (lst)
// 	{
// 		if (lst->index == res)
// 			return (i);
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_sorted(t_stack **list)
// {
// 	t_stack	*tmp;

// 	tmp = *list;
// 	while (tmp && tmp->next)
// 	{
// 		if (tmp->index > tmp->next->index)
// 			return (-1);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

// void	sort_25(t_stack **list_a, t_stack **list_b)
// {
// 	int	index;
// 	//int	ind;
// 	int	cust;
// 	//int ind_2;

// 	//ind_2 = size_list(*list_b);
// 	ft_sorted(list_a);
// 	if (list_b)
// 	{
// 		//printlist(*list_b);
// 		//ind = -1;
// 		//index = get_next_index(list_b, ind, ind_2);
// 		//cust = min_cust(index, size_list(*list_b));
// 		if(check_cust(index, size_list(*list_b)) == 0)
// 		{
// 			while (cust <= 25)
// 			{
// 				fun_rb(list_b);
// 				//cust++;
// 			}
// 		}
// 		else if (check_cust(index, size_list(*list_b)) == 1)
// 		{
// 			while (cust >= 0)
// 			{
// 				fun_rrb(list_b);
// 				//cust--;
// 			}
// 		}
// 	}
// }

void	ft_check_index_aux(t_stack **list_a, int index, int where)
{
	//int	index;
	int	cust;
	//int size;
	//size = size_list(*list_a);
	if (list_a)
	{
		cust = min_cust(where, size_list(*list_a));
		ft_printf("------------>CUST= | %d | | %d |\n", cust, check_cust(where, size_list(*list_a)));
		if(check_cust(where, size_list(*list_a)) == 0)
		{
			while (cust > 0)
			{
				fun_rra(list_a);
				cust--;
			}
		}
		else if (check_cust(index, size_list(*list_a)) == 1)
		{
			while (cust > 0)
			{
				fun_ra(list_a);
				cust--;
			}	
		}
	}
}

void	ft_check_index_1(t_stack **list_a, t_stack **list_b, int start, int end)
{
	t_stack		*lst;
	int			where;

	lst = *list_a;
	where = 0;
	while (lst)
	{	
		printf("|------------------------------------------>>>>>>>>>>>>>>>>>>>>>> %d |\n",	lst->index);
		if (lst->index >= start && lst->index <= end)
		{
			ft_check_index_aux(list_a, lst->index, where);
			fun_pb(list_b, list_a);
			lst = *list_a;
			where = 0;
		}
		lst = lst->next;
		where++;
	}
	printlist(*list_b);
}

void	sort2(t_stack **list_a, t_stack **list_b, int size)
{
	int	chunk;
		x`
	if (size == 100)
	{
		chunk = 1;
		while (ft_sorted(list_a) != 1 && chunk < 5)
		{
			if (chunk == 1)
				ft_check_index_1(list_a, list_b, 0, 24);
			else if (chunk == 2)
				ft_check_index_1(list_a, list_b, 25, 49);
			else if (chunk == 3)
				ft_check_index_1(list_a, list_b, 50, 74);
			else if (chunk == 4)
				ft_check_index_1(list_a, list_b, 75, 99);
			chunk++;
		}
	}
}
// void	sort(t_stack **list_a, t_stack **list_b, int size)
// {
// 	int	i;

// 	if (size == 100)
// 	{
// 		while (ft_sorted(list_a) != 1))
// 		{
// 			i = 0;
// 			while (i < 25)
// 			{
// 				fun_pb(list_b, list_a);
// 				i++;
// 			}
// 			sort_25(list_a, list_b);
// 		}
// 	}
// }

// int	ft_sorted_b(t_stack **list)
// {
// 	t_stack	*tmp;

// 	tmp = *list;
// 	while (tmp->next)
// 	{
// 		if (tmp->index < tmp->next->index)
// 			return (-1);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

