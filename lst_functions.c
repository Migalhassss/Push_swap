/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:37:16 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/20 11:37:16 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ftlstadd_back(t_stack **stack, t_stack *news)
{
	t_stack	*tmp;

	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = news;
	news->prev = tmp;
}

t_stack	*new_list(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->index = -1;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

int	size_list(t_stack *list)
{
	int		i;
	t_stack	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*list_last(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	lst_addfront(t_stack **list, t_stack *news)
{
	if (!list || !news)
		return ;
	if (!(*list))
	{
		*list = news;
		(*list)->prev = NULL;
		(*list)->next = NULL;
		return ;
	}
	(*list)->prev = news;
	news->next = *list;
	*list = news;
	news->prev = NULL;
}
