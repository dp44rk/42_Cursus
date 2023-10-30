/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:21:39 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:07:47 by dpark            ###   ########.fr       */
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

static void	rotate(t_stack *stack)
{
	int	prev;
	int	i;

	if (stack->now > 1)
	{
		prev = stack->s[stack->now - 1];
		i = -1;
		while (++i < stack->now)
			swap_element(&prev, &(stack->s[i]));
	}
}

void	ra(t_args *x)
{
	rotate(x->a);
}

void	rb(t_args *x)
{
	rotate(x->b);
}

void	rr(t_args *x)
{
	rotate(x->a);
	rotate(x->b);
}
