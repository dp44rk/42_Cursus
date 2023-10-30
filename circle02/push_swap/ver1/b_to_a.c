/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:41 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:08:01 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pivot_b(t_info *info)
{
	info->pb = info->high - (info->len / 3) - ((info->len % 3) == 1);
	info->ps = info->pb - (info->len / 3) - ((info->len % 3) == 2);
}

static void	divide_b(t_stack *a, t_stack *b, t_info *info, int len)
{
	while (len)
	{
		if (b->top->data > info->pb)
		{
			op("pa", b, a);
			(info->cnt_pa)++;
		}
		else if (b->top->data <= info->pb && b->top->data > info->ps)
		{
			op("pa", b, a);
			op("ra", a, NULL);
			(info->cnt_pa)++;
			(info->cnt_ra)++;
		}
		else
		{
			op("rb", b, NULL);
			(info->cnt_rb)++;
		}
		len--;
	}
}

void	b_to_a(t_stack *a, t_stack *b, int len)
{
	t_info	info;

	if (len <= 2)
	{
		if (len == 2 && b->top->data < b->top->next->data)
			op("sb", b, NULL);
		op("pa", b, a);
		if (len == 2)
			op("pa", b, a);
		return ;
	}
	info_init(b, &info, len);
	set_pivot_b(&info);
	divide_b(a, b, &info, len);
	a_to_b(a, b, info.cnt_pa - info.cnt_ra);
	restore_stack(a, b, info.cnt_ra, "rrr");
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
}
