/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:36:19 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/20 11:36:19 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	free_list(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

static int	check_doubles(t_stack *list)
{
	int		tmp;
	t_stack	*clone;

	while (list != NULL && list->next != NULL)
	{
		tmp = list->content;
		clone = list;
		
		while (clone->next != NULL)
		{
			clone = clone->next;
			if (clone->content == tmp)
				return (0);
		}
		list = list->next;
	}
	return (1);
}

static int plswork(int argc, char **argv, t_stack **list_a)
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

void	printlist(t_stack *head)
{
	t_stack *temporary = head;
	int i;

	i = 0;
	while (temporary != NULL)
	{
		ft_printf("| Node N°%d|>>>>>>>>>>>>>>>>>>>>>> %d |\n", i, temporary->index);
		temporary = temporary->next;
		i++;
	}
	ft_printf("\n");
}
int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	if (argc == 1)
		return (ft_printf("Error\n"));
	else if (ftisdigit(argv) == 0)
		return (ft_printf("Error\n"));
	list_a = NULL;
	list_b = NULL;
	plswork(argc, argv, &list_a);
	if (check_doubles(list_a) == 0)
		return (ft_printf("Error\n"));
	get_index(&list_a);
	if (ft_sorted(&list_a) != 1)
	{
		if (size_list(list_a) <= 5)
		{
			easy_sort(&list_a, &list_b);
		}
		else
			sort(&list_a, &list_b, size_list(list_a));
	}
	printlist(list_b);

	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
