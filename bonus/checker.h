/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:38:55 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/28 14:38:55 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack
{
	struct s_stack		*next;
	struct s_stack		*prev;
	int					content;
	int					index;
}	t_stack;

int				plswork(int argc, char **argv, t_stack **list_a);
int				ftsorted(t_stack **list);
int				bftisdigit(char **argv);
int				bcheck_doubles(t_stack *list);
void			ftlstadd_back(t_stack **stack, t_stack *news);
t_stack			*new_list(int content);
void			lst_addfront(t_stack **list, t_stack *news);
t_stack			*list_last(t_stack *list);
int				size_list(t_stack *list);

//========================Rotate=========================|;
void			brotate(t_stack **stack);
void			bfun_ra(t_stack **list_a);
void			bfun_rb(t_stack **list_b);
void			bfun_rr(t_stack **list_a, t_stack **list_b);
//=======================================================|;

//========================Reverse==========================|;
void			breverse(t_stack **stack);
void			bfun_rra(t_stack **list_a);
void			bfun_rrb(t_stack **list_b);
void			bfun_rrr(t_stack **list_a, t_stack **list_b);
//=========================================================|;

//=========================Swap===========================|;
void			bfun_sa(t_stack **list_a);
void			bfun_sb(t_stack **list_b);
void			bfun_ss(t_stack **list_a, t_stack **list_b);
//========================================================|;

//=========================Push===========================|;
void			bfun_pa(t_stack **list_a, t_stack **list_b);
void			bfun_pb(t_stack **list_b, t_stack **list_a);
//========================================================|;

#endif