/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:06 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/20 11:51:05 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"

void ft_move_a(t_stack **list_a, t_stack **list_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = size_list(*list_a);
	size_b = size_list(*list_b);
	while (*list_b != NULL)
	{
		i = best_number_b(list_b, size_b, list_a, size_a);
		if (i < 0)
			while (i++ < 0)
				fun_rrb(list_b);
		else if (i > 0)
			while (i-- > 0)
				fun_rb(list_b);
		fun_pa(list_b, list_a);
		size_a++;
		size_b--;
	}	
}

int	get_arr(t_stack *list)
{
	int i;void	get_index(t_stack **list)
	i = 0;
	tmp = list;
	size = size_list(list);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return(ft_printf("Error\n"));
	while (i > size)
	{
		arr[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	
	return (arr);
}

int best_number_a(t_stack *list_a, int size, int *arr, int max)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (list_a != NULL)
	{
		i = 0;
		while (list_a->index != arr[i] && i < max)
		{
			if (i == max - 1)
				return (pos);
			i++;
		}
		list_a = list_a->next;
		pos++;
	}
	size = -1;
	return (size);
}*/