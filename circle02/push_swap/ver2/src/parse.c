/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:02:34 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	get_number_len(int ac, char **av, int *dest)
{
	int		cnt;
	int		i;
	char	*s;

	cnt = 0;
	i = 0;
	while (++i < ac)
	{
		s = av[i];
		while (true)
		{
			s = ft_atoi(s, NULL);
			if (s == NULL)
				return (false);
			cnt++;
			if (*s == '\0')
				break ;
			if (*s != ' ')
				return (false);
			s++;
		}
	}
	*dest = cnt;
	return (true);
}

static void	fill_number_to_a(int size, int ac, char **av, int *a)
{
	int		i;
	char	*s;

	i = 0;
	while (++i < ac)
	{
		s = av[i];
		while (true)
		{
			s = ft_atoi(s, &(a[--size]));
			if (*s == '\0')
				break ;
			s++;
		}
	}
}

static void	set_b(int *b, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		b[i] = -1;
}

bool	parse(t_args *x, int ac, char **av)
{
	if (!get_number_len(ac, av, &(x->number_len)))
		return (false);
	x->a->now = x->number_len;
	x->a->s = ft_calloc(x->number_len, sizeof(int));
	x->b->s = ft_calloc(x->number_len, sizeof(int));
	x->origin = ft_calloc(x->number_len, sizeof(int));
	if (!(x->a->s) || !(x->b->s) || !(x->origin))
		exit_invalid(x, NULL);
	fill_number_to_a(x->number_len, ac, av, x->a->s);
	if (!convert_numbers(x->origin, x->a->s, x->a->now))
		return (false);
	set_b(x->b->s, x->number_len);
	return (true);
}
