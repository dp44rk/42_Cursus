/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:52 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:08:07 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_init(t_stack *a, t_stack *b, t_info *info)
{
	ft_memset((void *)a, 0, sizeof(t_stack));
	ft_memset((void *)b, 0, sizeof(t_stack));
	ft_memset((void *)info, 0, sizeof(t_info));
}

static void	sort_2_to_3(t_stack *a, int len)
{
	if (len == 1)
		return ;
	if (len == 3 && a->top->data == 3)
		op("ra", a, NULL);
	else if (len == 3 && a->top->next->data == 3)
		op("rra", a, NULL);
	if (a->top->data > a->top->next->data)
		op("sa", a, NULL);
}

static void	rotate_for_4_to_5(t_stack *a, int len)
{
	if (a->top->next->data == len)
		op("ra", a, NULL);
	if (a->top->data == len)
		op("ra", a, NULL);
	if (a->top->next->next->data == len)
		op("rra", a, NULL);
	if (len == 5 && a->top->next->next->next->data == len)
		op("rra", a, NULL);
}

static bool	is_ascend(t_stack *stack, int cnt)
{
	t_node	*curr;

	curr = stack->top;
	while (cnt > 1)
	{
		if (curr->data > curr->next->data)
			return (false);
		curr = curr->next;
		--cnt;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_info	info;

	if (argc == 1)
		return (0);
	stack_init(&a, &b, &info);
	parse_av(argv, &a);
	if (is_ascend(&a, a.numofdata))
		return (0);
	if (a.numofdata <= 3)
		sort_2_to_3(&a, a.numofdata);
	else if (a.numofdata <= 5)
	{
		rotate_for_4_to_5(&a, a.numofdata);
		a_to_b(&a, &b, a.numofdata - 1);
	}
	else
		a_to_b(&a, &b, a.numofdata);
	return (0);
}
