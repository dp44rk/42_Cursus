/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:17:10 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 10:51:26 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t elt_size)
{
	void	*arr;

	arr = malloc(count * elt_size);
	if (arr == 0)
		return (0);
	ft_memset(arr, 0, elt_size * count);
	return (arr);
}
