/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:51 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_zero_index(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->now)
		if (a->s[i] == 0)
			return (i);
	return (-1);
}

void	final_proc(t_args *x)
{
	int		zero;
	int		command;

	while (x->b->now)
		do_act(x, PA);
	zero = get_zero_index(x->a);
	if (zero < x->a->now - zero)
		command = RRA;
	else
		command = RA;
	while (x->a->s[0] != 0)
		do_act(x, command);
}
