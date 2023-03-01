/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:07:54 by micarrel          #+#    #+#             */
/*   Updated: 2023/02/27 10:08:28 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_arr2(t_stack *b, int *num)
{
	int	d;

	if (!b || !num)
		return (0);
	d = 0;
	while (b)
	{
		num[d] = b->index;
		b = b->next;
		d++;
	}
	return (*num);
}
