/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:30 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:31:32 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_cmd_str(int cmd)
{
	if (cmd == SA)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (cmd == SB)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	else if (cmd == SS)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	else if (cmd == PA)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	else if (cmd == PB)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	else if (cmd == RA)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	else if (cmd == RB)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	else if (cmd == RR)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	else if (cmd == RRA)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (cmd == RRB)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	else if (cmd == RRR)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

void	answer_print(t_args *x)
{
	t_cmd	*cur;

	cur = x->cmds;
	while (cur)
	{
		print_cmd_str(cur->cmd);
		cur = cur->next;
	}
}
