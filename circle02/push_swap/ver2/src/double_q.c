/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:53:52 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	my_sort_a(t_args *x, int pivot[2], int repeat)
{
	int	top;

	while (!x->finish && repeat--)
	{
		top = x->a->now - 1;
		if (x->a->now > 1 && x->a->s[top] <= pivot[0])
			do_act(x, RA);
		else if (x->a->s[top] <= pivot[1])
		{
			do_act(x, PB);
			if (x->b->now > 1)
				do_act(x, RB);
		}
		else
			do_act(x, PB);
	}
}

static void	my_sort_b(t_args *x, int pivot[2], int repeat)
{
	int	top;

	while (!x->finish && repeat--)
	{
		top = x->b->now - 1;
		if (x->b->s[top] <= pivot[0])
			do_act(x, PA);
		else if (x->b->s[top] <= pivot[1])
		{
			do_act(x, PA);
			if (x->a->now > 1)
				do_act(x, RA);
		}
		else if (x->b->now > 1)
			do_act(x, RB);
	}
}

void	double_qa(t_args *x, int low, int high, int n)
{
	int	pivot[2];
	int	repeat;
	int	top;

	if (x->finish)
		return ;
	while (low <= high && x->a->s[low] == low)
		n = high - ++low + 1;
	top = x->a->now - 1;
	if (n == 2 && !is_order(x->a->s[top], x->a->s[top - 1], x->number_len))
		do_act(x, SA);
	if (n <= 2)
		return ;
	pivot[0] = low - 1 + (n / 3) + ((n % 3) == 2);
	pivot[1] = pivot[0] + (n / 3) + ((n % 3) == 2);
	my_sort_a(x, pivot, n);
	repeat = (n / 3) + ((n % 3) == 2);
	while (!x->finish && repeat--)
		do_act(x, RRR);
	double_qa(x, low, pivot[0], pivot[0] - low + 1);
	double_qb(x, pivot[0] + 1, pivot[1], pivot[1] - pivot[0]);
	double_qb(x, pivot[1] + 1, high, high - pivot[1]);
}

void	double_qb(t_args *x, int low, int high, int n)
{
	int	pivot[2];
	int	repeat;
	int	top;

	if (x->finish)
		return ;
	top = x->b->now - 1;
	if (n == 2 && !is_order(x->b->s[top - 1], x->b->s[top], x->number_len))
		do_act(x, SB);
	if (n <= 2)
	{
		do_act(x, PA);
		if (n == 2)
			do_act(x, PA);
		return ;
	}
	pivot[0] = low - 1 + (n / 3) + ((n % 3) == 1);
	pivot[1] = pivot[0] + (n / 3) + ((n % 3) == 2);
	my_sort_b(x, pivot, n);
	double_qa(x, low, pivot[0], pivot[0] - low + 1);
	repeat = (n / 3) + ((n % 3) == 2);
	while (!x->finish && repeat--)
		do_act(x, RRR);
	double_qa(x, pivot[0] + 1, pivot[1], pivot[1] - pivot[0]);
	double_qb(x, pivot[1] + 1, high, high - pivot[1]);
}
