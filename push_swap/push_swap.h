/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:36:21 by micarrel          #+#    #+#             */
/*   Updated: 2023/01/20 11:36:21 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct	s_stack
{
	struct s_stack		*next;
	struct s_stack		*prev;
	int					content;
	int					index;
}	t_stack;

//======================List Functions======================|;
void			ftlstadd_back(t_stack **stack, t_stack *news);
t_stack			*new_list(int content);
//==========================================================|;

//==============Check numbers==============|;
int				ftisdigit(char **argv);
//=========================================|;
void			printlist(t_stack *head);

void	get_index(t_stack **list);

void	easy_sort(t_stack **list_a, t_stack **list_b);

int size_list(t_stack *list);
int	ft_sorted(t_stack **list);
int	order(t_stack **list, int size);
void	index_reset(t_stack **list);
void	rotate_to_first(t_stack **lst, int size);
t_stack	*list_last(t_stack *list);
void	lst_addfront(t_stack **list, t_stack *news);

void	rotate(t_stack **stack);
void	reverse(t_stack **stack);

void	fun_sa(t_stack **list_a);
void	fun_sb(t_stack **list_b);
void	fun_ss(t_stack **list_a, t_stack **list_b);

void	fun_pa(t_stack **list_b, t_stack **list_a);
void	fun_pb(t_stack **list_b, t_stack **list_a);

void	fun_ra(t_stack **list_a);
void	fun_rb(t_stack **list_b);
void	fun_rr(t_stack **list_a, t_stack **list_b);

void	fun_rra(t_stack **list_a);
void	fun_rrb(t_stack **list_b);
void	fun_rrr(t_stack **list_a, t_stack **list_b);

#endif