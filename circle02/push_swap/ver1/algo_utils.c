/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:39 by dpark             #+#    #+#             */
/*   Updated: 2022/08/31 18:08:00 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_stack(t_stack *a, t_stack *b, int cnt, char *command)
{
	if (ft_strcmp("rrr", command))
	{
		while (cnt > 0)
		{
			op(command, a, b);
			cnt--;
		}
		return ;
	}
	if (ft_strcmp("pa", command))
	{
		while (cnt > 0)
		{
			op(command, b, a);
			cnt--;
		}
		return ;
	}
}

void	info_init(t_stack *s, t_info *info, int len)
{
	int		i;
	t_node	*cur;

	ft_memset((void *)info, 0, sizeof(t_info));
	i = 0;
	cur = s->top;
	while (i < len)
	{
		if (i == 0 || info->low > cur->data)
			info->low = cur->data;
		if (i == 0 || info->high < cur->data)
			info->high = cur->data;
		cur = cur->next;
		i++;
	}
	info->len = len;
}
