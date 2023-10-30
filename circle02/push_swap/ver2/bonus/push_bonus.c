/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:53:05 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:07:13 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_stack *from, t_stack *to)
{
	if (from->now)
	{
		to->s[to->now] = from->s[from->now - 1];
		from->s[from->now - 1] = -1;
		to->now = to->now + 1;
		from->now = from->now - 1;
	}
}

void	pa(t_args *x)
{
	push(x->b, x->a);
}

void	pb(t_args *x)
{
	push(x->a, x->b);
}
