/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:16:03 by dpark             #+#    #+#             */
/*   Updated: 2022/09/02 18:53:45 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dub_check_and_add_data(t_stack *a, int val)
{
	t_node	*curr;
	int		data;

	data = 1;
	if (a->numofdata < 1)
		return (data);
	curr = a->top;
	while (1)
	{
		if (curr->origin == val)
			ft_print_error();
		else if (curr->origin > val)
			(curr->data)++;
		else
			data ++;
		curr = curr->next;
		if (curr == a->top)
			return (data);
	}
}

void	parse_av(char **argv, t_stack *a)
{
	char	**temp;
	int		val;
	int		data;
	int		i;

	argv++;
	while (*argv)
	{
		temp = ft_split(*argv, ' ');
		i = 0;
		while (temp[i])
		{
			val = ft_atoi(temp[i]);
			data = dub_check_and_add_data(a, val);
			insert_node_to_bottom(&a, val, data);
			free(temp[i++]);
		}
		free(temp);
		argv++;
	}
}
