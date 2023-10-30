/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:01:14 by dpark             #+#    #+#             */
/*   Updated: 2023/01/15 23:37:37 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	*ft_calloc(size_t count, size_t elt_size)
{
	void	*arr;

	arr = malloc(count * elt_size);
	if (arr == 0)
		return (0);
	ft_memset(arr, 0, elt_size * count);
	return (arr);
}

void	*safe_alloc(size_t cnt, size_t size)
{
	void	*rtn;

	rtn = ft_calloc(cnt, size);
	if (!rtn)
	{
		ft_putstr_fd("Error: memory allocation failure!", STDERR_FILENO);
		g_rtn = 137;
		exit(137);
	}
	return (rtn);
}
