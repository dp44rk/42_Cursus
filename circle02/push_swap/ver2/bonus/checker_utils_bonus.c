/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:00:30 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:02:21 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_command_bonus(t_args *x, int cmd)
{
	t_cmd	*new;
	t_cmd	*last_node;

	last_node = ft_lstlast(x->cmds);
	new = ft_lstnew(cmd);
	if (new == NULL)
		exit_invalid(x, NULL);
	x->cmds_len = x->cmds_len + 1;
	if (last_node)
		last_node->next = new;
	else
		x->cmds = new;
}

static void	(*get_f(int cmd))(t_args *x)
{
	if (cmd == SA)
		return (sa);
	else if (cmd == SB)
		return (sb);
	else if (cmd == SS)
		return (ss);
	else if (cmd == PA)
		return (pa);
	else if (cmd == PB)
		return (pb);
	else if (cmd == RA)
		return (ra);
	else if (cmd == RB)
		return (rb);
	else if (cmd == RR)
		return (rr);
	else if (cmd == RRA)
		return (rra);
	else if (cmd == RRB)
		return (rrb);
	else if (cmd == RRR)
		return (rrr);
	return (NULL);
}

bool	do_command(t_args *x)
{
	t_cmd	*cur;
	void	(*fp)(t_args *);

	cur = x->cmds;
	while (cur)
	{
		fp = get_f(cur->cmd);
		if (fp == NULL)
			return (false);
		fp(x);
		cur = cur->next;
	}
	return (true);
}

bool	is_aligned(t_args *x)
{
	int	i;
	int	*data;

	data = x->a->s;
	if (x->number_len != x->a->now)
		return (false);
	i = -1;
	while (++i < x->number_len)
		if (data[i] != i)
			return (false);
	return (true);
}
