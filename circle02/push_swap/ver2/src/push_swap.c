/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:02:34 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_zero_index(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->now)
		if (a->s[i] == 0)
			return (i);
	return (-1);
}

static void	pre_rotate(t_args *x)
{
	int	zero;
	int	command;

	zero = get_zero_index(x->a);
	if (zero < x->a->now - zero)
		command = RRA;
	else
		command = RA;
	while (x->a->s[0] != 0)
		do_act(x, command);
}

int	main(int ac, char **av)
{
	t_args	*x;

	if (ac == 1)
		exit_valid(NULL, NULL, STDERR_FILENO);
	if (!t_args_init(&x))
		exit_valid(NULL, "Error\n", STDERR_FILENO);
	if (!parse(x, ac, av))
		exit_valid(x, "Error\n", STDERR_FILENO);
	check_every_order(x, x->a, x->b);
	if (x->number_len == 3 && !x->finish)
		do_act(x, SA);
	if (!(x->finish))
	{
		if (x->number_len <= 5)
			pre_rotate(x);
		double_qa(x, 0, x->number_len - 1, x->number_len);
	}
	final_proc(x);
	answer_print(x);
	exit_valid(x, NULL, STDOUT_FILENO);
}
