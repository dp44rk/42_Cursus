/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:53:58 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_order(int a, int b, int number_len)
{
	if (a == 0 && b == number_len - 1)
		return (true);
	if (a > b)
		return (true);
	return (false);
}

static bool	is_order2(int a, int b, int number_len)
{
	if (a == 0 && b == number_len - 1)
		return (true);
	if (a == b + 1)
		return (true);
	return (false);
}

void	check_every_order(t_args *x, t_stack *a, t_stack *b)
{
	int	i;
	int	n;

	if (x->finish)
		return ;
	n = x->number_len;
	if (n == 1)
	{
		x->finish = true;
		return ;
	}
	if ((a->now && b->now && !is_order2(b->s[b->now - 1], a->s[a->now - 1], n)))
		return ;
	i = 0;
	while (++i < a->now)
		if (!is_order2(a->s[i], a->s[i - 1], n))
			return ;
	i = 0;
	while (++i < b->now)
		if (!is_order2(b->s[i - 1], b->s[i], n))
			return ;
	x->finish = true;
}
