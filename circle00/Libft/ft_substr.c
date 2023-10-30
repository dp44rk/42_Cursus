/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:11:00 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 15:52:26 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	size;
	size_t	j;

	j = 0;
	size = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (0);
	while (s[j] && j < len)
	{
		c[j] = s[start];
		start++;
		j++;
	}
	c[j] = '\0';
	return (c);
}
