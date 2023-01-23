//=======================================|;
static t_stack	*get_first(t_stack **list);
void			get_index(t_stack **list);
//=======================================|;

//===========================Sort===========================|;
static void		tree_sort(t_stack **list_a);
static void		four_sort(t_stack **list_a, t_stack **list_b);
void			easy_sort(t_stack **list_a, t_stack **list_b);
//==========================================================|;




// ANTIGO
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct	s_stack
{
	struct s_stack		*next;
	struct s_stack		*prev;
	int					content;
	int					index;
}	t_stack;

//=================Split strings & Add to list=================|;
static int		plswork(int argc, char **argv, t_stack **list_a);
//=============================================================|;

//======================List Functions======================|;
void			ftlstadd_back(t_stack **stack, t_stack *news);
t_stack			*new_list(int content);
static void		free_list(t_stack **stack);
//==========================================================|;

//==============Check numbers==============|;
static int		check_doubles(t_stack *list);
int				ftisdigit(char **argv);
//=========================================|;
void			printlist(t_stack *head);
#endif