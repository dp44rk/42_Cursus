/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:54:31 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 11:00:12 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*un_ptr1;
	unsigned char	*un_ptr2;

	un_ptr1 = (unsigned char *) ptr1;
	un_ptr2 = (unsigned char *) ptr2;
	i = 0;
	while (i < num)
	{
		if (*un_ptr1 != *un_ptr2)
			return (*un_ptr1 - *un_ptr2);
		un_ptr1++;
		un_ptr2++;
		i++;
	}
	return (0);
}
