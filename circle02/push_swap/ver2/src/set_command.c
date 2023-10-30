/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:50 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static bool	can_removed(int last_cmd, int added_cmd)
{
	if (last_cmd == added_cmd)
	{
		if (last_cmd == SA || last_cmd == SB || last_cmd == SS)
			return (true);
		return (false);
	}
	else
	{
		if ((last_cmd == RA || last_cmd == RB || last_cmd == RR) && \
			(last_cmd + 3 == added_cmd))
			return (true);
		if ((last_cmd == RRA || last_cmd == RRB || last_cmd == RRR) && \
			(last_cmd == added_cmd + 3))
			return (true);
		return (false);
	}
}

static bool	do_merged(t_args *x, t_cmd *last_node, int last_cmd, int added_cmd)
{
	if ((last_cmd == SA || last_cmd == RA || last_cmd == RRA) && \
		(last_cmd + 1 == added_cmd))
		last_node->cmd = last_cmd + 2;
	else if ((last_cmd == SB || last_cmd == RB || last_cmd == RRB) && \
		(last_cmd == added_cmd + 1))
		last_node->cmd = last_cmd + 1;
	else if (can_removed(last_cmd, added_cmd))
	{
		ft_lst_delone(&(x->cmds), last_node);
		x->cmds_len = x->cmds_len - 1;
	}
	else
		return (false);
	return (true);
}

static void	add_command(t_args *x, int cmd)
{
	t_cmd	*new;
	t_cmd	*last_node;

	last_node = ft_lstlast(x->cmds);
	if (!last_node || !do_merged(x, last_node, last_node->cmd, cmd))
	{
		new = ft_lstnew(cmd);
		if (new == NULL)
			exit(EXIT_FAILURE);
		x->cmds_len = x->cmds_len + 1;
		if (last_node)
			last_node->next = new;
		else
			x->cmds = new;
	}
}

void	do_act(t_args *x, int cmd)
{
	void	(*fp)(t_args *);

	fp = get_f(cmd);
	fp(x);
	add_command(x, cmd);
	check_every_order(x, x->a, x->b);
}
