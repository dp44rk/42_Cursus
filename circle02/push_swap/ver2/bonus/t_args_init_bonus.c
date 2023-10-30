/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:08:46 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:08:51 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	t_args_init(t_args **x)
{
	t_args	*ret;

	ret = ft_calloc(1, sizeof(t_args));
	if (!ret)
		return (false);
	ret->a = ft_calloc(1, sizeof(t_stack));
	ret->b = ft_calloc(1, sizeof(t_stack));
	if (!ret->a || !ret->b)
	{
		free_args(ret);
		return (false);
	}
	*x = ret;
	return (true);
}
