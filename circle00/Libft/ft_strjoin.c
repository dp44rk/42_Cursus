/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:21:30 by dpark             #+#    #+#             */
/*   Updated: 2022/03/25 17:21:31 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*c;

	i = ft_strlen(s1);
	i += ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (0);
	while (*s1)
		*c++ = *s1++;
	while (*s2)
		*c++ = *s2++;
	*c = '\0';
	while (i > 0)
	{
		c--;
		i--;
	}
	return (c);
}
