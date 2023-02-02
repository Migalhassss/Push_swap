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
void			lst_addfront(t_stack **list, t_stack *news);
t_stack			*new_list(int content);
int 			size_list(t_stack *list);
t_stack			*list_last(t_stack *list);
//==========================================================|;

//==============Check numbers=========|;
int				ftisdigit(char **argv);
//====================================|;

//=====================================|;
void			printlist(t_stack *head);
//=====================================|;

//================Index Functions==========|;
void			get_index(t_stack **list);
void			index_reset(t_stack **list);
//=========================================|;

//=====================Easy sort functions==================|;
void			easy_sort(t_stack **list_a, t_stack **list_b);
int				ft_sorted(t_stack **list);
int				order(t_stack **list, int size);
void			rotate_to_first(t_stack **lst, int size);
//==========================================================|;

//========================Rotate=========================|;
void			rotate(t_stack **stack);
void			fun_ra(t_stack **list_a);
void			fun_rb(t_stack **list_b);
void			fun_rr(t_stack **list_a, t_stack **list_b);
//=======================================================|;

//========================Reverse==========================|;
void			reverse(t_stack **stack);
void			fun_rra(t_stack **list_a);
void			fun_rrb(t_stack **list_b);
void			fun_rrr(t_stack **list_a, t_stack **list_b);
//=========================================================|;

//=========================Swap===========================|;
void			fun_sa(t_stack **list_a);
void			fun_sb(t_stack **list_b);
void			fun_ss(t_stack **list_a, t_stack **list_b);
//========================================================|;

//=========================Push===========================|;
void			fun_pa(t_stack **list_a, t_stack **list_b);
void			fun_pb(t_stack **list_b, t_stack **list_a);
//========================================================|;

//========================SORT 100========================|;
//void	sort(t_stack **list_a, t_stack **list_b, int size);
void			sort2(t_stack **list_a, t_stack **list_b, int size);
void			ft_check_index(t_stack **list_a, t_stack **list_b, int end, int size);
void			ft_check_index_aux(t_stack **list_a, int where);

void 			sort_25(t_stack **list_a, t_stack **list_b);
int				is_sorted(t_stack **list);
int				check_cust(int index, int size);
int				min_cust(int index, int size);
int  ftcheck(t_stack *list, int ind);
//========================================================|;

#endif