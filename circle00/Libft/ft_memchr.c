/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:53:07 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 11:02:05 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{	
	unsigned char	*ptr2;
	unsigned char	value2;
	size_t			i;

	i = 0;
	ptr2 = (unsigned char *)ptr;
	value2 = (unsigned char )value;
	while (i < num)
	{
		if (*ptr2 == value2)
			return (ptr2);
		i++;
		ptr2++;
	}
	return (0);
}
