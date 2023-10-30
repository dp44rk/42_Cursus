/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:53:05 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:21:27 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap_array(int *stack_a, int *origin, int now)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < now)
	{
		temp = origin[i];
		origin[i] = stack_a[i];
		stack_a[i] = temp;
	}
}

static bool	get_index(int *stack_a, int *dest, int i, int now)
{
	int	j;
	int	cnt;
	int	target;

	target = stack_a[i];
	cnt = 0;
	j = -1;
	while (++j < now)
	{
		if (i == j)
			continue ;
		if (target == stack_a[j])
			return (false);
		if (target < stack_a[j])
			cnt++;
	}
	*dest = cnt;
	return (true);
}

bool	convert_numbers(int *origin, int *stack_a, int len)
{
	int		i;
	int		index;

	i = -1;
	while (++i < len)
	{
		if (!get_index(stack_a, &index, i, len))
			return (false);
		origin[i] = index;
	}
	swap_array(stack_a, origin, len);
	return (true);
}
