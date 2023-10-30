/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:10:31 by dpark             #+#    #+#             */
/*   Updated: 2022/04/04 14:22:15 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_makearr(const char *s1, char *str, int front, int back)
{
	size_t	i;

	i = 0;
	while (front <= back)
	{
		str[i] = s1[front];
		front++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*str;

	front = 0;
	back = ft_strlen(s1) - 1;
	while (find_set(s1[front], set) && s1[front] != '\0')
		front++;
	if (s1[front] == '\0')
		return (ft_strdup(""));
	else
	{
		while (find_set(s1[back], set))
			back--;
	}
	str = (char *)malloc(sizeof(char) * (back - front + 1) + 1);
	if (!str)
		return (0);
	ft_makearr(s1, str, front, back);
	return (str);
}
