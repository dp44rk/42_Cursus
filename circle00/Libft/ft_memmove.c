/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:55:36 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 11:02:26 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{	
	size_t				i;
	unsigned char		*destt;
	unsigned char		*srcc;

	destt = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (destt > srcc)
	{
		while (num > 0)
		{
			destt[num - 1] = srcc[num - 1];
			num--;
		}
	}
	if (destt < srcc)
	{
		i = 0;
		while (i < num)
		{
			destt[i] = srcc[i];
			i++;
		}
	}
	return (dest);
}
