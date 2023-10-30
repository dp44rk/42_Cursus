/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:02:23 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	j_free(void *p)
{
	if (p)
		free(p);
}

void	free_args(t_args *x)
{
	j_free(x->origin);
	if (x->a)
	{
		j_free(x->a->s);
		free(x->a);
	}
	if (x->b)
	{
		j_free(x->b->s);
		free(x->b);
	}
	ft_lstclear(&(x->cmds));
}
