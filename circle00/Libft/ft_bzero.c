/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:55:16 by dpark             #+#    #+#             */
/*   Updated: 2022/03/10 21:55:17 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*char_ptr;

	char_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		*(char_ptr + i) = 0;
		i++;
	}
}
