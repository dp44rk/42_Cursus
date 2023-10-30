/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:23:43 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 11:01:30 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*c;

	j = 0;
	i = ft_strlen(s);
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (0);
	while (j < i)
	{
		c[j] = s[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}
