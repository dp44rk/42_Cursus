/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:33 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:07:58 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pivot_a(t_info *info)
{
	info->pb = info->high - (info->len / 3) - ((info->len % 3) == 2);
	info->ps = info->pb - (info->len / 3) - ((info->len % 3) == 2);
}

static void	divide_a(t_stack *a, t_stack *b, t_info *info, int len)
{
	while (len)
	{
		if (a->top->data > info->pb)
		{
			op("ra", a, NULL);
			(info->cnt_ra)++;
		}
		else if (a->top->data <= info->pb && a->top->data > info->ps)
		{
			op("pb", a, b);
			op("rb", b, NULL);
			(info->cnt_pb)++;
			(info->cnt_rb)++;
		}
		else
		{
			op("pb", a, b);
			(info->cnt_pb)++;
		}
		len--;
	}
}

void	a_to_b(t_stack *a, t_stack *b, int len)
{
	t_info	info;

	if (len <= 2)
	{
		if (len == 2 && a->top->data > a->top->next->data)
			op("sa", a, NULL);
		return ;
	}
	info_init(a, &info, len);
	set_pivot_a(&info);
	divide_a(a, b, &info, len);
	restore_stack(a, b, info.cnt_ra, "rrr");
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
	b_to_a(a, b, info.cnt_pb - info.cnt_rb);
}
