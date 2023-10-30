/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:54:58 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 14:21:15 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		if (to_find[j] == str[i + j])
		{
			while (to_find[j] && str[i + j])
			{
				if (to_find[j] != str[i + j] || (i + j) >= len)
					break ;
				j++;
			}
			if (to_find[j] == '\0')
				return (&((char *)str)[i]);
		}
		i++;
	}
	return (0);
}
