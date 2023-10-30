/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:52 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:30:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_invalid(t_args *x, char *s)
{
	if (x)
		free_args(x);
	if (s)
		ft_putstr_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_valid(t_args *x, char *s, int fd)
{
	if (x)
		free_args(x);
	if (s)
		ft_putstr_fd(s, fd);
	exit(EXIT_SUCCESS);
}
