/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:38:53 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 14:38:53 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_list(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	free_list(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

void	result_line2(char *line, t_stack **a_list, t_stack **b_list)
{
	if (!(ft_strncmp(line, "rb", ft_strlen(line) - 1)))
		bfun_rb(b_list);
	else if (!(ft_strncmp(line, "rr", ft_strlen(line) - 1)))
		bfun_rr(a_list, b_list);
	else if (!(ft_strncmp(line, "sb", ft_strlen(line) - 1)))
		bfun_sb(b_list);
	else if (!(ft_strncmp(line, "ss", ft_strlen(line) - 1)))
		bfun_ss(a_list, b_list);
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	result_line(char *line, t_stack **a_list, t_stack **b_list)
{
	if (!(ft_strncmp(line, "sa", ft_strlen(line) - 1)))
		bfun_sa(a_list);
	else if (!(ft_strncmp(line, "pa", ft_strlen(line) - 1)))
		bfun_pa(a_list, b_list);
	else if (!(ft_strncmp(line, "pb", ft_strlen(line) - 1)))
		bfun_pb(b_list, a_list);
	else if (!(ft_strncmp(line, "rra", ft_strlen(line) - 1)))
		bfun_rra(a_list);
	else if (!(ft_strncmp(line, "rrb", ft_strlen(line) - 1)))
		bfun_rrb(b_list);
	else if (!(ft_strncmp(line, "rrr", ft_strlen(line) - 1)))
		bfun_rrr(a_list, b_list);
	else if (!(ft_strncmp(line, "ra", ft_strlen(line) - 1)))
		bfun_ra(a_list);
	else
		result_line2(line, a_list, b_list);
}

void	read_finish(char *line, t_stack **a_list, t_stack **b_list)
{
	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			ft_printf("Error\n");
			exit(0);
		}
		result_line(line, a_list, b_list);
		free(line);
		line = get_next_line(0);
	}
	if (ftsorted(a_list) == 1 && size_list(*b_list) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	char	*line;

	if (argc == 1)
		return (0);
	else if (bftisdigit(argv) == 0)
		return (ft_printf("Error\n"));
	list_a = NULL;
	list_b = NULL;
	line = NULL;
	plswork(argc, argv, &list_a);
	if (bcheck_doubles(list_a) == 0)
	{
		free_list(&list_a);
		return (ft_printf("Error\n"));
	}
	read_finish(line, &list_a, &list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
