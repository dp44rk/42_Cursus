/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:54 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:31:47 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_element(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	swap(t_stack *stack)
{
	if (stack->now > 1)
		swap_element(&(stack->s[stack->now - 2]), \
					&(stack->s[stack->now - 1]));
}

void	sa(t_args *x)
{
	swap(x->a);
}

void	sb(t_args *x)
{
	swap(x->b);
}

void	ss(t_args *x)
{
	swap(x->a);
	swap(x->b);
}
