/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:21:39 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:06:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap_element(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	reverse_rotate(t_stack *stack)
{
	int	prev;
	int	i;

	if (stack->now > 1)
	{
		prev = stack->s[0];
		i = stack->now;
		while (--i >= 0)
			swap_element(&prev, &(stack->s[i]));
	}
}

void	rra(t_args *x)
{
	reverse_rotate(x->a);
}

void	rrb(t_args *x)
{
	reverse_rotate(x->b);
}

void	rrr(t_args *x)
{
	reverse_rotate(x->a);
	reverse_rotate(x->b);
}
