/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:08:54 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:31:46 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	t_args_init(t_args **x)
{
	t_args	*ret;

	ret = ft_calloc(1, sizeof(t_args));
	if (!ret)
		exit_invalid(NULL, NULL);
	ret->a = ft_calloc(1, sizeof(t_stack));
	ret->b = ft_calloc(1, sizeof(t_stack));
	if (!ret->a || !ret->b)
		exit_invalid(ret, NULL);
	*x = ret;
	return (true);
}
