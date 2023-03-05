/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:06:05 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 15:06:05 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	plswork(int argc, char **argv, t_stack **list_a)
{
	char	**split;
	int		i;
	int		j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		split = ft_split(argv[j], ' ');
		if (!split[i])
			return (0);
		if (ft_atoi(split[i]) == -1)
		{
			free_split(split);
			ft_printf("Error\n");
			exit(1);
		}
		while (split[i])
		{
			ftlstadd_back(list_a, new_list(ft_atoi(split[i])));
			i++;
		}
		free_split(split);
		j++;
	}
	return (1);
}

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

int	ftsorted(t_stack **list)
{
	t_stack	*tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int	bftisdigit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 1)
				j++;
			else if (argv[i][j] == '-' || argv[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
