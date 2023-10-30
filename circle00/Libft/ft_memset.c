/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:56:34 by dpark             #+#    #+#             */
/*   Updated: 2022/03/10 21:56:35 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*char_ptr;
	size_t			i;

	i = 0;
	char_ptr = (unsigned char *)ptr;
	while (i < num)
	{
		*((unsigned char *)char_ptr + i) = (unsigned char) value;
		i++;
	}
	return (char_ptr);
}
